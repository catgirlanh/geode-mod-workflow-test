#include <Geode/modify/MenuLayer.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/loader/Event.hpp>

using namespace geode::prelude;

class $modify(MenuLayer) {
    struct Fields {
        EventListener<web::WebTask> m_listener;
    };

// everything from here up is boilerplate
    bool init() {
        if (!MenuLayer::init()) {
            return false;
        }

        m_fields->m_listener.bind([] (web::WebTask::Event* e) {
            if (web::WebResponse* res = e->getValue()) {
                if (res->ok()) {
// if the request was successful 
                    log::info("raw: {}", res->string().unwrapOr("Uh oh!"));
                    log::info("extracted url: {}", res->json()["url"].as_string());
                    log::info("source url: {}", res->json()["source_url"].as_string());
                }
            } else if (web::WebProgress* p = e->getProgress()) {
// if the request is in progress, say how far along it is
                log::info("progress: {}", p->downloadProgress().value_or(0.f));
            } else if (e->isCancelled()) {
// say if the request errored or was canceled
                log::info("The request was cancelled... So sad :(");
            }
        });

// logic for starting the request
        auto req = web::WebRequest(); m_fields->m_listener.setFilter(req.get("https://nekos.best/api/v2/neko"));
        return true;
    }
};

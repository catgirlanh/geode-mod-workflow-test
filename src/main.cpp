#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

int mrrow = 0;

class $modify (MrrpMrrow, MenuLayer)
{
	struct Fields
	{
        EventListener<web::WebTask> listener;
        EventListener<web::WebTask> listener2;
		LoadingCircle* lcircle;
		CCLayerColor* bg;
    };

	bool init()
	{
		if (!MenuLayer::init())
			return false;
		
		auto myButton = CCMenuItemSpriteExtra::create(
			CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
			this,
			menu_selector(MrrpMrrow::onMeow)
		);

		auto menu = this->getChildByID("bottom-menu");
		menu->addChild(myButton);

		myButton->setID("my-button"_spr);

		menu->updateLayout();

		return true;
	}

	void onMeow(CCObject*)
	{
		if (!m_fields->lcircle)
		{
			auto circle = LoadingCircle::create();
			circle->show();

			auto bg = CCLayerColor::create(ccc4(0, 0, 0, 0));
			bg->runAction(CCFadeTo::create(0.5f, 100));

			circle->addChild(bg, -1);

			m_fields->lcircle = circle;
			m_fields->bg = bg;
		}

		m_fields->listener2.bind([this] (web::WebTask::Event* e)
		{
            if (web::WebResponse* res = e->getValue()) {
                if (res->ok()) {
                    auto imgData = res->data();
                    auto image = Ref(new CCImage());
                    image->initWithImageData(const_cast<uint8_t*>(res->data().data()),res->data().size());
                    std::string theKey = fmt::format("{}/logo-{}", Mod::get()->getID(), mrrow);
                    auto texture = CCTextureCache::get()->addUIImage(image,theKey.c_str());
                    image->release();

					auto spr = CCSprite::createWithTexture(texture);
					spr->setPosition(this->getContentSize() / 2);
					limitNodeSize(spr, ccp(250, 250), 1, 0);
					this->addChild(spr, 420);

					mrrow++;
                }
            }
			else if (e->isCancelled()) {
                log::info("The request was cancelled... So sad :(");
                this->release();
            }
			else if (e->getProgress())
			{
				log::info("nyaaaaaaaaaaa: {}", e->getProgress()->downloadProgress().value_or(0));
			}
        });

		m_fields->listener.bind([this] (web::WebTask::Event* e)
		{
            if (web::WebResponse* res = e->getValue()) {
                if (res->ok()) {
					log::info("str: {}", res->string().unwrapOr("mrrow"));

                    auto json = res->json().unwrapOr("{}");

					auto results = json["results"].as_array();
					auto data = results.at(0).as_object();
					auto url = data["url"].as_string();

					log::info("url: {}", url);

					auto req = web::WebRequest();
        			m_fields->listener2.setFilter(req.get(url));
                }
            } else if (e->isCancelled()) {
                log::info("The request was cancelled... So sad :(");
                this->release();
            }
        });

        auto req = web::WebRequest();
        m_fields->listener.setFilter(req.get("https://nekos.best/api/v2/neko"));
	}
};

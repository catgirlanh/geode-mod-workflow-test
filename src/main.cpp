/**
 * Include the Geode headers.
 */
#include <Geode/Geode.hpp>

/**
 * Brings cocos2d and all Geode namespaces to the current scope.
 */
using namespace geode::prelude;

#include <Geode/modify/PlayLayer.hpp>

class $modify(PlayLayer) {
	virtual void destroyPlayer(PlayerObject* p0, GameObject* p1) {}
};
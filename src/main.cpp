#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include "utils/save.hpp"
#include "utils/swap.hpp"

using namespace geode::prelude;

$on_mod(Loaded)
{
    Save::setSwappedYet(false);
    Save::setPrevID(0);
}

class $modify(PlayLayer)
{
    bool init(GJGameLevel* p0, bool p1, bool p2)
    {
        if(!PlayLayer::init(p0, p1, p2))
            return false;

        addEventListener(KeybindSettingPressedEventV3(GEODE_MOD_ID, "swapLevel"), [this](const Keybind& keybind, bool down, bool repeat,  double timestamp)
        {
            auto currentPlayLayer = static_cast<PlayLayer*>(GameManager::sharedState()->getGameLayer());
            if (down && !repeat && currentPlayLayer != nullptr)
            {
                if(!currentPlayLayer->m_isPaused)
                    currentPlayLayer->pauseGame(false);
                Swap::swap();
            }
        });
        return true;
    }
};
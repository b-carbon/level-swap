#include "myPlayLayer.hpp"

bool myPlayLayer::init(GJGameLevel* level, bool useReplay, bool dontCreateObjects)
{
    if(!PlayLayer::init(level, useReplay, dontCreateObjects))
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
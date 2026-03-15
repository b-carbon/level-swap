#include "myPlayLayer.hpp"

bool myPlayLayer::init(GJGameLevel* level, bool useReplay, bool dontCreateObjects)
{
    if(!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;
        
        this->addEventListener(KeybindSettingPressedEventV3(GEODE_MOD_ID, "swapLevel"), [this](const Keybind& keybind, bool down, bool repeat,  double timestamp)
        {
            if (down && !repeat)
            {
                if(this->m_level->m_dailyID <= 0 && !this->m_level->m_gauntletLevel && this->m_level->m_levelType != GJLevelType::Main)
                {
                    if(!this->m_isPaused)
                        this->pauseGame(false);
                    Swap::swap();
                }
            }
        });
    return true;
}
#include <Geode/Geode.hpp>
#include "save.hpp"

using namespace geode::prelude;

class Swap {
    public:
        static void swap()
        {
            if(Mod::get()->hasSavedValue("level ID"))
            {
                GJGameLevel* swapTolvl = GameLevelManager::get()->getSavedLevel(Save::getLevel());
                if(swapTolvl->m_levelID == GameManager::sharedState()->m_currentLevelID)
                {
                    if(Save::getSwappedYet())
                    {
                        Save::setSwappedYet(false);
                        GJGameLevel* swapFromlvl = GameLevelManager::get()->getSavedLevel(Save::getPrevID());
                        switchToScene(PlayLayer::create(swapFromlvl, false, false));
                        GameManager::sharedState()->m_currentLevelID = Save::getPrevID();
                    }
                    else 
                        FLAlertLayer::create("Level Swap", "Can't swap: Can't start on target level.","OK")->show();
                }
                else
                {
                    if(!swapTolvl->m_levelNotDownloaded)
                    {
                        Save::setSwappedYet(true);
                        Save::setPrevID(GameManager::sharedState()->m_currentLevelID);
                        switchToScene(PlayLayer::create(swapTolvl, false, false));
                        GameManager::sharedState()->m_currentLevelID = Save::getLevel();
                    }
                    else
                        FLAlertLayer::create("Error", "Saved level is not downloaded", "OK")->show();
                }
            }
            else 
            {
                FLAlertLayer::create("Level Swap", "Set a level first!", "OK")->show();
            }
        }
};

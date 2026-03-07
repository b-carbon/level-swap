#include <Geode/Geode.hpp>
#include "save.hpp"

using namespace geode::prelude;

class Swap {

    public:
        static void swap()
        {
            if(Mod::get()->hasSavedValue("level ID"))
            {
                GJGameLevel* swapTolvl = static_cast<GJGameLevel*>(GameLevelManager::sharedState()->m_onlineLevels->objectForKey(std::to_string(Save::getLevel())));
                bool sameLvl = swapTolvl->m_levelID == GameManager::sharedState()->m_currentLevelID;
                if(sameLvl)
                {
                    if(Save::getSwappedYet())
                    {
                        Save::setSwappedYet(false);
                        GJGameLevel* swapFromlvl = static_cast<GJGameLevel*>(GameLevelManager::sharedState()->m_onlineLevels->objectForKey(std::to_string(Save::getPrevID())));
                        CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f, PlayLayer::scene(swapFromlvl, false, false)));
                        GameManager::sharedState()->m_currentLevelID = Save::getPrevID();
                    }
                    else 
                    {
                        FLAlertLayer::create("Level Swap", "Can't swap: Can't start on target level.","Ok")->show();
                    }
                }
                else
                {
                    if(!swapTolvl->m_levelNotDownloaded)
                    {
                        Save::setSwappedYet(true);
                        Save::setPrevID(GameManager::sharedState()->m_currentLevelID);
                        CCDirector::sharedDirector()->replaceScene( PlayLayer::scene(swapTolvl, false, false));
                        GameManager::sharedState()->m_currentLevelID = Save::getLevel();
                    }
                    else
                        FLAlertLayer::create("Error", "Saved level is not downloaded", "OK")->show();
                }
            }
            else 
            {
                FLAlertLayer::create("Level Swap", "Set a level first!", "Ok")->show();
            }
        }
};
#include "../hooks/myPauseLayer.hpp"
#include "../utils/swap.hpp"

void myPauseLayer::customSetup() {
    PauseLayer::customSetup();

    if(!(GameManager::sharedState()->getGameLayer()->m_level->m_dailyID > 0 ||
        GameManager::sharedState()->getGameLayer()->m_level->m_levelType == GJLevelType::Main ||
        GameManager::sharedState()->getGameLayer()->m_level->m_gauntletLevel))
    {
        auto menu = this->getChildByID("left-button-menu");

        auto spr = CCSprite::create("swap-icon.png"_spr);
        auto btnSpr = CircleButtonSprite::create(spr, CircleBaseColor::Green, CircleBaseSize::Small);
        btnSpr->setScale(.95f);

        auto btn = CCMenuItemSpriteExtra::create(btnSpr, this, menu_selector(myPauseLayer::onButtonClicked));
        btn->setID("swap-button");

        menu->addChild(btn);
        menu->updateLayout();
    }

}

void myPauseLayer::onButtonClicked(CCObject*)
{
    Swap::swap();
}

//do in future: add keybind for swap

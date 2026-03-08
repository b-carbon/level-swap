#include "../hooks/myPauseLayer.hpp"
#include "../utils/swap.hpp"

void myPauseLayer::customSetup() {
    PauseLayer::customSetup();

    auto currentLevel = GameManager::sharedState()->getGameLayer()->m_level;
    if(!(currentLevel->m_dailyID > 0 || currentLevel->m_levelType == GJLevelType::Main || currentLevel->m_gauntletLevel))
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

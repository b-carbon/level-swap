#include "myLevelInfoLayer.hpp"
#include "../utils/save.hpp"
#include "../utils/swap.hpp"

bool myLevelInfoLayer::init(GJGameLevel* p0, bool p1)
{
    if (!LevelInfoLayer::init(p0, p1)) 
        return false;

    Save::setSwappedYet(false);
    FMODAudioEngine::sharedEngine()->disableMetering();
    log::debug("metering is {}", FMODAudioEngine::sharedEngine()->m_metering);

    m_fields->m_lvlID = p0->m_levelID;

    if(!(p0->m_dailyID > 0 || p0->m_gauntletLevel))
    {
        auto menu = getChildByID("left-side-menu");

        auto lbl = CCLabelBMFont::create("Set", "bigFont.fnt");
        auto btnSpr = CircleButtonSprite::create(lbl);

        auto btn = CCMenuItemSpriteExtra::create(btnSpr, this, menu_selector(myLevelInfoLayer::onButtonClicked));
        btn->setID("setswap-button");
        menu->addChild(btn);
        menu->updateLayout();
    }

    return true;
}

void myLevelInfoLayer::onButtonClicked(CCObject* )
{
    Save::setLevel(m_fields->m_lvlID);
    FLAlertLayer::create("Level Swap","Level Updated!","OK")->show();
}
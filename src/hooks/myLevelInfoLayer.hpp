#include <Geode/Geode.hpp>
#include <Geode/modify/LevelInfoLayer.hpp>

using namespace geode::prelude;

class $modify(myLevelInfoLayer, LevelInfoLayer)
{
    struct Fields
    {
        int m_lvlID;
    };

    bool init(GJGameLevel* p0, bool p1);
    void onButtonClicked(CCObject*);
};
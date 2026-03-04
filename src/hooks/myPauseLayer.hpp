#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>

using namespace geode::prelude;

class $modify(myPauseLayer, PauseLayer) {

    void customSetup();
    void onButtonClicked(CCObject* );

    void getlvlID(CCObject* );
};
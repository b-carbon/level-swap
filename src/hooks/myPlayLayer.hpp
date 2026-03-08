#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include "../utils/swap.hpp"

using namespace geode::prelude;

class $modify(myPlayLayer, PlayLayer)
{
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects);
    void destructor()
    {
        PlayLayer::~PlayLayer();
        FMODAudioEngine::sharedEngine()->enableMetering();
    }
};
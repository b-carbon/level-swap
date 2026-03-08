#include <Geode/Geode.hpp>
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include "utils/save.hpp"
#include "utils/swap.hpp"

using namespace geode::prelude;

$on_mod(Loaded)
{
    Save::setSwappedYet(false);
    Save::setPrevID(0);
}
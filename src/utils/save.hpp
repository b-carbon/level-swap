#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class Save 
{
    public:
        static void setLevel(const int& ID) {Mod::get()->setSavedValue("level ID", ID);}
        static int getLevel() {return Mod::get()->getSavedValue<int>("level ID");}
        static void setSwappedYet(const bool& sw) {Mod::get()->setSavedValue("swapped", sw);}
        static bool getSwappedYet() {return Mod::get()->getSavedValue<bool>("swapped");}
        static void setPrevID(const int& ID) {Mod::get()->setSavedValue("previous ID", ID);}
        static int getPrevID() {return Mod::get()->getSavedValue<int>("previous ID");}
};
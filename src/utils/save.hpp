#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

class Save 
{
    public:
        static void setLevel(int);
        static int getLevel();
        static void setSwappedYet(bool);
        static bool getSwappedYet();
        static void setPrevID(int);
        static int getPrevID();
};
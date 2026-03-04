#include "save.hpp"

void Save::setLevel(int ID)
{
    Mod::get()->setSavedValue("level ID", ID);
}

int Save::getLevel()
{
    return Mod::get()->getSavedValue<int>("level ID");
}

void Save::setSwappedYet(bool sw)
{
    Mod::get()->setSavedValue("swapped", sw);
}

bool Save::getSwappedYet()
{
    return Mod::get()->getSavedValue<bool>("swapped");
}

void Save::setPrevID(int ID)
{
    Mod::get()->setSavedValue("previous ID", ID);
}

int Save::getPrevID()
{
    return Mod::get()->getSavedValue<int>("previous ID");
}


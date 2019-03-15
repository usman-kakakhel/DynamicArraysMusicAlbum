#include "Song.h"


Song::Song(const string sName, const int sMins, const int sSecs) 
{
    name = sName;
    mins = sMins;
    secs = sSecs;
}

Song::~Song()
{}

Song::Song(const Song &songToCopy)
{
    *this = songToCopy;
}

void Song::operator=(const Song &right)
{
    name = right.name;
    mins = right.mins;
    secs = right.secs;
}

string Song::getName()
{
    return name;
}

int Song::getMins()
{
    return mins;
}

int Song::getSecs()
{
    return secs;
}
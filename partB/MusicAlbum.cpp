#include "MusicAlbum.h"
#include <iostream>

MusicAlbum::MusicAlbum(const string maArtist, const string maTitle, const int maYear)
{
    artist = maArtist;
    title = maTitle;
    year = maYear;
    noSongs = 0;
    songs = NULL;
}

MusicAlbum::~MusicAlbum()
{
    if (songs != NULL)
        delete[] songs;
}

MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy)
{
    artist = maToCopy.artist;
    title = maToCopy.title;
    year = maToCopy.year;
    noSongs = maToCopy.noSongs;
    if (maToCopy.songs != NULL)
    {
        songs = new Song[noSongs];
        for (int i = 0; i < noSongs; i++)
        {
            songs[i] = maToCopy.songs[i];
        }
    }
    else{
        songs = NULL;
    }
    
}

void MusicAlbum::operator=(const MusicAlbum &right)
{
    artist = right.artist;
    title = right.title;
    year = right.year;
    noSongs = right.noSongs;

    if (songs != NULL)
        delete[] songs;
        
    if (right.songs != NULL)
    {
        songs = new Song[noSongs];
        for (int i = 0; i < noSongs; i++)
        {
            songs[i] = right.songs[i];
        }
    }
    else{
        songs = NULL;
    }
}

string MusicAlbum::getMusicAlbumArtist()
{
    return artist;
}

string MusicAlbum::getMusicAlbumTitle()
{
    return title;
}

int MusicAlbum::getMusicAlbumYear()
{
    return year;
}


void MusicAlbum::calculateMusicAlbumLength(int &minutes, int &seconds)
{
    minutes = 0;
    seconds = 0;

    for (int i = 0; i < noSongs; i++)
    {
        minutes = minutes + songs[i].getMins();
        seconds = seconds + songs[i].getSecs();
    }

    minutes = minutes + (seconds / 60);
    seconds = seconds % 60;
}

bool MusicAlbum::addSong(const string sName, const int sMins, const int sSecs)
{
    for (int i = 0; i < noSongs; i++)
    {
        if (songs[i].getName() == sName)
            return false;
    }
    noSongs++;
    Song *temp;
    temp = new Song[noSongs];
    Song arg;
    
    for (int j = 0; j < noSongs - 1; j++)
    {
        temp[j] = songs[j];
    }

    Song s(sName, sMins, sSecs);
    temp[noSongs - 1] = s;

    if (songs != NULL)
        delete[] songs;

    songs = temp;
    return true;
}

bool MusicAlbum::removeSongs()
{
    if (noSongs == 0)
        return false;
    
    noSongs = 0;
    if (songs != NULL)
        delete[] songs;

    songs = NULL;
    return true;
}
#include "MAC.h"
#include <iostream>

using namespace std;
MAC::MAC()
{
    noOfMusicAlbums = 0;
    musicAlbums = NULL;
}

MAC::~MAC()
{
    if (musicAlbums != NULL)
        delete[] musicAlbums;

}

MAC::MAC(const MAC &macToCopy)
{
    noOfMusicAlbums = macToCopy.noOfMusicAlbums;

    musicAlbums = new MusicAlbum[noOfMusicAlbums];

    for (int i = 0; i < noOfMusicAlbums; i++)
    {
        musicAlbums[i] = macToCopy.musicAlbums[i];
    }
}

void MAC::operator=(const MAC &right)
{

    noOfMusicAlbums = right.noOfMusicAlbums;

    if (musicAlbums != NULL)
        delete[] musicAlbums;

    musicAlbums = new MusicAlbum[noOfMusicAlbums];

    for (int i = 0; i < noOfMusicAlbums; i++)
    {
        musicAlbums[i] = right.musicAlbums[i];
    }
}

bool MAC::addMusicAlbum(const string maArtist, const string maTitle, const int maYear)
{
    for (int i = 0; i < noOfMusicAlbums; i++)
    {
        if ((musicAlbums[i].getMusicAlbumArtist() == maArtist) && (musicAlbums[i].getMusicAlbumTitle() == maTitle))
            return false;
    }

    MusicAlbum myAlbumm(maArtist, maTitle, maYear);
    noOfMusicAlbums++;
    MusicAlbum *temp = new MusicAlbum[noOfMusicAlbums];

    if (musicAlbums != NULL)
    {
        for (int j = 0; j < noOfMusicAlbums - 1; j++)
        {
            temp[j] = musicAlbums[j];
        }
        delete[] musicAlbums;
    }

    musicAlbums = temp;
    musicAlbums[noOfMusicAlbums - 1] = myAlbumm;

    return true;
}

bool MAC::removeMusicAlbum(const string maArtist, const string maTitle)
{

    for (int i = 0; i < noOfMusicAlbums; i++)
    {
        if ((musicAlbums[i].getMusicAlbumArtist() == maArtist) && (musicAlbums[i].getMusicAlbumTitle() == maTitle))
        {
            for (int j = i; j < noOfMusicAlbums - 1; j++)
            {
                musicAlbums[j] = musicAlbums[j + 1];
            }
            noOfMusicAlbums--;

            MusicAlbum *temp = new MusicAlbum[noOfMusicAlbums];
            for (int z = i; z < noOfMusicAlbums; z++)
            {
                temp[z] = musicAlbums[z];
            }
            delete[] musicAlbums;
            musicAlbums = temp;

            return true;
        }
    }

    return false;
}

int MAC::getMusicAlbums(MusicAlbum *&allMusicAlbums)
{
    allMusicAlbums = new MusicAlbum[noOfMusicAlbums];

    for (int i = 0; i < noOfMusicAlbums; i++)
    {
        allMusicAlbums[i] = musicAlbums[i];
    }

    return noOfMusicAlbums;
}



bool MAC::addSong(const string maArtist, const string maTitle, const string sName, const int sMins, const int sSecs)
{
    for (int i = 0; i < noOfMusicAlbums; i++)
    {
        if ((musicAlbums[i].getMusicAlbumArtist() == maArtist) && (musicAlbums[i].getMusicAlbumTitle() == maTitle))
                return musicAlbums[i].addSong(sName, sMins, sSecs);
    }
    return false;
}

bool MAC::removeSongs(const string maArtist, const string maTitle)
{
    for (int i = 0; i < noOfMusicAlbums; i++)
        {
            if ((musicAlbums[i].getMusicAlbumArtist() == maArtist) && (musicAlbums[i].getMusicAlbumTitle() == maTitle))
                 return musicAlbums[i].removeSongs();
        }
    return false;
}

void MAC::calculateAvgMusicAlbumLength(int &minutes, int &seconds)
{
    int minutesL = 0;
    int secondsL = 0;
    minutes = 0;
    seconds = 0;
    for (int i = 0; i < noOfMusicAlbums; i++)
    {
        musicAlbums[i].calculateMusicAlbumLength(minutesL, secondsL);
        minutes = minutes + minutesL;
        seconds = seconds + secondsL;    
    }

    seconds = seconds + (60 * minutes);
    seconds = seconds / noOfMusicAlbums;
    minutes = seconds / 60;
    seconds = seconds % 60;
}

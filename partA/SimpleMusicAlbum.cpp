#include "SimpleMusicAlbum.h"

MusicAlbum::MusicAlbum(const string maArtist, const string maTitle, const int maYear)
{
    artist = maArtist;
    title = maTitle;
    year = maYear;
}

MusicAlbum::~MusicAlbum()
{
}

MusicAlbum::MusicAlbum(const MusicAlbum &maToCopy)
{
    *this = maToCopy;
}

void MusicAlbum::operator=(const MusicAlbum &right)
{
    artist = right.artist;
    title = right.title;
    year = right.year;
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

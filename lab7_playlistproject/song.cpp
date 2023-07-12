#include "song.h"

Song::Song()
{
    title = "";
    artist = "";
}

Song::Song(string title, string artist)
{
    this->title = title;
    this->artist = artist;
}

// getters
string Song::getTitle()
{
    return title;
}

string Song::getArtist()
{
    return artist;
}

// setters
void Song::setTitle(string title)
{
    this->title = title;
}

void Song::setArtist(string artist)
{
    this->artist = artist;
}

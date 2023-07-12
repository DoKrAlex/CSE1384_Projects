#include <string>

using std::string;

#ifndef SONG_H
#define SONG_H


class Song
{
    private:
        string title, artist;

    public:
        Song();
        Song(string title, string artist);

        // getters
        string getTitle();
        string getArtist();

        // setters
        void setTitle(string title);
        void setArtist(string artist);
};

#endif // SONG_H

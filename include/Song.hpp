#ifndef SONG_HPP
#define SONG_HPP
#include <string>

class Song{
    std::string title;
    std::string artist;
    std::string album;
    unsigned int year_rel;

public:
    Song();

    void set_title(const std::string& title);
    void set_artist(const std::string& artist);
    void set_album(const std::string& album);
    void set_year_rel(const int year_rel);

    std::string get_title();
    std::string get_artist();
    std::string get_album();
    unsigned int get_year_rel();

};


#endif
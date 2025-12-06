#ifndef SONG_HPP
#define SONG_HPP
#include <string>
#include <vector>

class Song{
    std::string title;
    std::string artist;
    std::string album;
    unsigned int year_rel;
    std::vector<std::string> genres;

public:
    Song();

    void set_title(const std::string& title);
    void set_artist(const std::string& artist);
    void set_album(const std::string& album);
    void set_year_rel(const int year_rel);
    void add_genre(const std::string& genre);


    std::string get_title() const;
    std::string get_artist() const;
    std::string get_album() const;
    unsigned int get_year_rel() const;
    std::vector<std::string> get_genres() const;

};


#endif
#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <vector>
#include <memory>
#include "Song.hpp"
#include <map>

class Database{

    static std::vector<std::unique_ptr<Song>> songs;
    static std::map<std::string, std::vector<Song*>> songs_by_artists;
    static std::map<std::string, std::vector<Song*>> songs_in_album;


    static bool artist_exists(const std::string& artist);
    static bool album_exists(const std::string& album);
public:
    

    Database();

    static void add_song(const Song& song);

    static void remove_song(const Song& song);
    static std::vector<std::unique_ptr<Song>>& get_songs();

};


#endif
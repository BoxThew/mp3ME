#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <vector>
#include <memory>
#include "Song.hpp"
#include <unordered_map>
#include <map>
#include <string> 
#include <utility>
#include <functional>


//removed structs
using art_alb_pair = std::pair<std::string, std::string>; //alias 

class Database{

    static std::vector<std::unique_ptr<Song>> songs;
    //this one is a hash table
    static std::unordered_map<std::string, std::vector<Song*>> songs_by_artists;

    //using a tree for album because pair wasnt being hashed.
    static std::map<art_alb_pair, std::vector<Song*>> songs_in_album;

    static bool artist_exists(const std::string& artist);
    static void make_artist(const std::string& artist);
    static void add_to_artist(const std::string& artist, Song *pSong);

    static bool album_exists(const art_alb_pair& album);
    static void make_album(const art_alb_pair& album);
    static void add_to_album(const art_alb_pair& album, Song *pSong);

public:
    

    Database();

    static void add_song(const Song& song);

    static void remove_song(const Song& song);
    static std::vector<std::unique_ptr<Song>>& get_all_songs();

};

#endif
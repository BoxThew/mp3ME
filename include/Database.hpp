#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <vector>
#include <memory>
#include "Song.hpp"

class Database{

    static std::vector<std::unique_ptr<Song>> songs;
public:
    

    Database();

    static void add_song(const Song& song);
    static void remove_song(const Song& song);
    static std::vector<std::unique_ptr<Song>>& get_songs();

};


#endif
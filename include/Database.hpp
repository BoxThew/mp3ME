#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <vector>
#include "Song.hpp"

class Database{
    static std::vector<Song*> songs;

public:
    Database();

    void add_song(Song* song);


    std::vector<Song*> get_songs();

};


#endif

#include "Database.hpp"
#include "Song.hpp"
#include <vector>
#include <memory>

std::vector<std::unique_ptr<Song>> Database::songs{};


Database::Database(){

}


void Database::add_song(const Song& song){
    songs.push_back(std::make_unique<Song>(song));
}

void Database::remove_song(const Song& song){
    //to do
}



std::vector<std::unique_ptr<Song>>& Database::get_songs(){return songs;}
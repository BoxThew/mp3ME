
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
<<<<<<< HEAD
void Databas::remove_song(const Song& song){
=======

void Database::remove_song(const Song& song){
>>>>>>> be2ab919b9271a086c5adf0a537b048321a117b2
    //to do
}



std::vector<std::unique_ptr<Song>>& Database::get_songs(){return songs;}
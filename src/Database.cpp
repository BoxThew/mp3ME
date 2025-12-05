
#include "Database.hpp"

#include <vector>


Database::Database(){

}


void Database::add_song(Song* song){
    songs.push_back(song);
}



std::vector<Song*> Database::get_songs(){return songs;}
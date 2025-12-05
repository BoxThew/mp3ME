#include "Song.hpp"
#include <string>
#include <vector>


Song::Song(){

}


void Song::set_title(const std::string& title){
    this->title = title;
}
void Song::set_artist(const std::string& artist){
    this->artist = artist;
}
void Song::set_album(const std::string& album){
    this->album = album;
}
void Song::set_year_rel(const int year_rel){
    this->year_rel = year_rel;
}
void Song::add_genre(const std::string& genre){
    this->genres.push_back(genre);
}


std::string Song::get_title(){return title;}
std::string Song::get_artist(){return artist;}
std::string Song::get_album(){return album;}
unsigned int Song::get_year_rel(){return year_rel;}
std::vector<std::string> Song::get_genres(){return genres;}
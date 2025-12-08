
#include "Database.hpp"
#include "Song.hpp"
#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include <utility>
#include <string>



std::vector<std::unique_ptr<Song>> Database::songs{};
std::unordered_map<std::string, std::vector<Song*>> Database::songs_by_artists{};
std::unordered_map<std::string, std::vector<Song*>> Database::songs_in_album{};


Database::Database() : song_pepper("Urdasalt2mypepper!"){

}

bool Database::artist_exists(const std::string& artist){
    return songs_by_artists.find(artist) != songs_by_artists.end();
}

void Database::add_to_artist(const std::string& artist, Song *pSong){
    songs_by_artists.at(artist).push_back(pSong);
}

bool Database::album_exists(const std::string& album){
    return songs_in_album.find(album) != songs_in_album.end(); 
}

void Database::make_artist(const std::string& artist){
    std::vector<Song*> artist_songs {};
    songs_by_artists[artist] = artist_songs;
}

void Database::make_album(const std::string& album){
    std::vector<Song*> album_songs {};
    songs_in_album[album] = album_songs;
}

void Database::add_to_album(const std::string& album, Song *pSong){
    songs_in_album.at(album).push_back(pSong);
}



void Database::add_song(const Song& song){
    std::unique_ptr<Song> spSong = std::make_unique<Song>(song);
    Song *pSong = spSong.get();

    std::string artist = song.get_artist();
    std::string album_title = song.get_album(); 

    if (!artist_exists(artist)){
        make_artist(artist);
    }

    add_to_artist(artist, pSong);


    //accomodate for salt and pepper maybe
    std::string album = artist + album_title;

    if (!album_exists(album)){
        make_album(album);
    }

    add_to_album(album, pSong);

    songs.push_back(std::move(spSong));
}



void Database::remove_song(const Song& song){
//TODO
    
}



std::vector<std::unique_ptr<Song>>& Database::get_all_songs(){return songs;}

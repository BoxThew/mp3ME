#include "PlayMedia.hpp"

#include <memory>
#include <vector>
#include <queue>
#include <stack> 
#include "SFML/Audio/SoundSource.hpp"

#include <ctime>
#include <iostream>
#include <chrono>
#include "Database.hpp"



PlayMedia::PlayMedia(){
    this->current_song = nullptr;
}

void PlayMedia::clear_queue(){
    queue.clear();
    while (!history.empty())
        history.pop();
    
    current_song = nullptr;
}

Song *PlayMedia::get_current_song() const{return current_song;}



//for entire song library
void PlayMedia::set_queue(const std::vector<std::unique_ptr<Song>>& songs){
    clear_queue();
    for (const auto& song : songs){
        queue.push_back(song.get());
    }
}

//for albums and songs by artists
void PlayMedia::set_queue(const std::vector<Song*>& songs){
    clear_queue();
    for (const auto& song : songs){
        queue.push_back(song);
    }
}





void PlayMedia::play_song(Song *song){
    if (!song){
        std::cout << "Invalid song. Is nullptr.\n";
        return;
    }
    std::vector<Song*> top_songs = Database::get_top_songs();
    std::cout << "===================\n" <<
        "Current top 5 songs:\n";
    for (int x = 1; x <= top_songs.size(); ++x){
        Song *tSong = top_songs.at(x - 1);
        std::cout << x << ") " << tSong->get_title() << " by " <<
        tSong->get_artist() << " with " << tSong->get_times_played() <<
        " times listened!\n";
    }

    std::cout << "===================\n";

    current_song = song;

    music.stop();

    if (!music.openFromFile(current_song->get_file_name())){
        std::cout << "Failed to play " <<
                current_song->get_title() << " by " <<
                current_song->get_artist() << ".\n";

        return;
    }

    std::cout << "Now playing " <<
                current_song->get_title() << " by " <<
                current_song->get_artist() << "!\n";

    current_song->inc_times_played();
    music.play();
}

void PlayMedia::play_from_idx(const std::vector<Song*>& songs, int idx){
    if (songs.empty()){
        std::cout << "No songs were passed in.\n";
        return;
    }

    if (idx < 0 || idx >= songs.size()){
        std::cout << "Index out of bounds.\n";
        return;
    }

    clear_queue();
    for (int x = idx; x < songs.size(); ++x){
        add_to_queue(songs.at(x));
    }

    for (int x = 0; x < idx; ++x){
        add_to_queue(songs.at(x));
    }

    if (!queue.empty()){
        play_song(queue.front());
    }


}

void PlayMedia::add_to_queue(Song *song){
    queue.push_back(song);
}




void PlayMedia::set_history(Song* song){
    if(song){
        history.push(song); 
    }
    else{
        std::cout << "Invalid(nullptr)"; 
    }
}



void PlayMedia::next_song(){
    set_history(current_song);
    queue.pop_front();
}

void PlayMedia::skip_song(){
    music.stop();
    set_history(current_song);
    std::cout << "Skipping song.\n";
    queue.pop_front();

}

void PlayMedia::prev_song(){
    if(history.empty()){ 
        std::cout << "History is empty.\n"; 
        return; 
    }
    else{

        Song *prev_song = history.top(); 
        history.pop(); 

        queue.push_front(prev_song);
        
    }
}

void PlayMedia::toggle_song(){
    if (music.getStatus() == sf::SoundSource::Status::Paused)
        music.play();
    
    else
        music.pause();
}
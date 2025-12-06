#include "PlayMedia.hpp"

#include <memory>
#include <vector>
#include <queue>
#include <stack> 
#include "SFML/Audio.hpp"
#include "SFML/Audio/SoundSource.hpp"
#include "SFML/System.hpp"

#include <ctime>
#include <iostream> 



void PlayMedia::set_queue(const std::vector<std::unique_ptr<Song>>& songs){
    for (const auto& song : songs){
        queue.push(song.get());
    }
}


//FIXME - incomplete / really messy, will come back.
std::vector<std::unique_ptr<Song>> PlayMedia::shuffle_queue(std::vector<std::unique_ptr<Song>> songs){
    srand(time(0));
    unsigned int songs_size = songs.size();
    for (int x = 0; x < songs_size; ++x){
        int rand_idx = rand() % songs_size;
        
        std::swap(songs[x], songs[rand_idx]);
    }
}

void PlayMedia::play_queue(){
    
    bool playing = true;
    while(!queue.empty()){
        Song *next_song = queue.front();
        sf::Music m(next_song->get_file_name());


        if(current_song != nullptr){
            set_history(current_song); 
        }
        current_song = next_song; 
        
        std::cout << "Now playing " << next_song->get_title() <<
                    " by " << next_song->get_artist() << "!\n\n";
        m.play();

        while (playing){
            if (!still_playing(m)){
                break;
            }

            char peeked_in = std::cin.peek();

            if (skip_song(peeked_in)){
                m.stop();
                std::cout << "Skipping song.\n";
                break;
            }

            if (prev_song(peeked_in)){
                //FIXME
            }

            sf::sleep(sf::milliseconds(60));
        
        }
        queue.pop();

    }

    std::cout << "Play queue is empty.\n";

}


void PlayMedia::set_history(Song* song){
    if(song != nullptr){
            history.push(song); 
    }
    else{
            std::cout << "Invalid(nullptr)"; 
    }
}

void PlayMedia::play_back(){
    if(history.empty()){ 
        std::cout << "History is empty.\n"; 
        return; 
    }
    else{

        Song* previous_song = history.top(); 
        history.pop(); 
        current_song = previous_song; 

        sf::Music m;
        if(!m.openFromFile(previous_song->get_file_name())){
            std::cout << "ERROR: file cannot be opened.\n" ; 
            return; 
        }
     
        std::cout << "Now replaying " << current_song->get_title() <<
                    " by " << current_song->get_artist() << "!\n\n";
        m.play();

        while(!still_playing){
            break; 
        }
    }
}




bool PlayMedia::still_playing(const sf::Music& music) const{
    return music.getStatus() != sf::SoundSource::Status::Stopped;
}

bool PlayMedia::skip_song(const char user_in) const{

    std::cin.get();
    std::cin.ignore(100, '\n');
    return user_in == '>';
}




bool PlayMedia::prev_song(const char user_in) const{

    //FIXME
    return false;
}
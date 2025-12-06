#include "PlayMedia.hpp"

#include <memory>
#include <vector>
#include <queue>
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"

#include <random>
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
    //no songs in queue
    bool playing = true;
    while(!queue.empty()){
        Song *next_song = queue.front();
        sf::Music m(next_song->get_file_name());

        std::cout << "Now playing " << next_song->get_title() <<
                    " by " << next_song->get_artist() << "!\n\n";
        m.play();

        while (playing){
            if (m.getStatus() == sf::SoundSource::Status::Stopped){
                break;
            }

            //test skip
            if (std::cin.peek() == '>'){
                std::cin.get();

                std::cin.ignore(1000, '\n');
                m.stop();
                std::cout << "Skipping song.\n";
                break;
            }

            sf::sleep(sf::milliseconds(60));
        
        }
        queue.pop();

    }

}
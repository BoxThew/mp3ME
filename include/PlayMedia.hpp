#ifndef PLAY_MEDIA_HPP
#define PLAY_MEDIA_HPP
#include "SFML/Audio/SoundSource.hpp"
#include "Song.hpp"
#include <vector>
#include <queue>
#include<stack> 
#include <memory>
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"


class PlayMedia{

    std::queue<Song*> queue;
    std::stack<Song*> history;
    Song* current_song = nullptr; 



public:
    void set_queue(const std::vector<std::unique_ptr<Song>>& songs);
    std::vector<std::unique_ptr<Song>> shuffle_queue(const std::vector<std::unique_ptr<Song>> songs);


    void play_queue();

    void set_history(Song* song);

    vois play_back(); 

    bool still_playing(const sf::Music& music) const;

    bool skip_song(const char user_in) const;

    bool prev_song(const char user_in) const;


};

#endif
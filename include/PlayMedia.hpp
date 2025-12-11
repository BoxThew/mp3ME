#ifndef PLAY_MEDIA_HPP
#define PLAY_MEDIA_HPP
#include "SFML/Audio/SoundSource.hpp"
#include "Song.hpp"
#include <vector>
#include <deque>
#include <stack> 
#include <memory>
#include "SFML/Audio.hpp"
#include "SFML/System.hpp"





class PlayMedia{

    std::deque<Song*> queue;
    std::stack<Song*> history;
    Song *current_song; 
    sf::Music music;



public:
    PlayMedia();


    void clear_queue();
    Song *get_current_song() const;
    void set_queue(const std::vector<std::unique_ptr<Song>>& songs);

    void set_queue(const std::vector<Song*>& songs);

    void add_to_queue(Song *song);


    void play_song(Song *song);

    void play_from_idx(const std::vector<Song*>& songs, int idx);



    void set_history(Song *song);



    void skip_song();

    void next_song();

    void prev_song();

    void toggle_song();






};

#endif
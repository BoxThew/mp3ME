#ifndef PLAY_MEDIA_HPP
#define PLAY_MEDIA_HPP
#include "Song.hpp"
#include <vector>


class PlayMedia{

    std::vector<Song> queue;



public:
    void set_queue(const std::vector<Song> songs);
    void shuffle_queue();


    void play_queue() const;
};

#endif
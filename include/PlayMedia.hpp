#ifndef PLAY_MEDIA_HPP
#define PLAY_MEDIA_HPP
#include "Song.hpp"
#include <vector>
#include <queue>
#include <memory>


class PlayMedia{

    std::queue<Song*> queue;



public:
    void set_queue(const std::vector<std::unique_ptr<Song>>& songs);
    std::vector<std::unique_ptr<Song>> shuffle_queue(const std::vector<std::unique_ptr<Song>> songs);


    void play_queue();
};

#endif
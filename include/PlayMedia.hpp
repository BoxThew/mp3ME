#ifndef PLAY_MEDIA_HPP
#define PLAY_MEDIA_HPP
#include "Song.hpp"
#include <vector>

namespace Compare{
    typedef bool (*Comparator)(Song, Song);

    bool artists(Song s1, Song s2){
        return s1.get_artist() <= s2.get_artist();
    }

    bool title(Song s1, Song s2){
        return s1.get_title() <= s2.get_title();
    }

}


class PlayMedia{

    std::vector<Song> queue;
    


public:
    void set_queue(const std::vector<Song> songs);
    void shuffle_queue();


    void play_queue() const;
};

#endif
#pragma once

#include "nx/audio.hpp"
#include <mpg123.h>
#include <SFML/Audio.hpp>

class AudioStream : public sf::SoundStream {
public:
    AudioStream();
    ~AudioStream();
    void open(nl::audio const &audio);
    sf::Time lengthTime;

private:
    bool onGetData(Chunk &data);
    void onSeek(sf::Time timeOffset);
    void mpg123assert(int result);
    void die();
    mpg123_handle *m_handle = nullptr;
    std::vector<unsigned char> m_buf;
    unsigned char const *m_begin;
    uint32_t m_length;
    long m_rate;
    enum {
        Mp3,
        Raw_S16LE_44100
    } m_type;
    uint32_t m_rawOffset;
    static int const rawbufsize = 1024;
};

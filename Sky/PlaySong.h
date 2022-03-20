#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class PlaySong
{
    String filename;

public:
    Music music;

    PlaySong(String file)
    {
        filename = file;
        music.openFromFile(filename);
        music.setLoop(true);
    }

    void Play();
    void Stop();
};
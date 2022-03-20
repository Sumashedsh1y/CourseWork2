#include <SFML/Graphics.hpp>
#include <iostream>
#include "BackDoor.h"
#include "PlaySong.h"
#include "UFO.h"
#include "Anim.h"
using namespace std;
using namespace sf;
int main()
{
    setlocale(LC_ALL, "Russian");

    RenderWindow window(VideoMode(1920, 1080), "Sky", Style::Fullscreen);
    int scene = 1;

    PlaySong q("Реквизиты\\Music\\Menu_Song.ogg");
    q.Play();

    while (window.isOpen())
    {
        if (scene == 1)
        {
            Anim q("Реквизиты\\menu\\", 6);
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == Event::KeyPressed)
                    if (event.key.code == Keyboard::Escape)
                        window.close();
            }
            window.clear();
            q.go_anim(window);
            window.display();
        }
    }

    return 0;
}
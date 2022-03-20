#include <SFML/Graphics.hpp>
#include <iostream>
#include "UFO.h"
using namespace std;
using namespace sf;
int main()
{
    RenderWindow window(VideoMode(1920, 1080), "SFML works!", Style::Fullscreen);
    UFO model(1000, 500, 50.f);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
                if (event.key.code == Keyboard::Escape)
                    window.close();
        }

        window.clear();
        window.draw(model.ufo());
        window.display();
    }

    return 0;
}
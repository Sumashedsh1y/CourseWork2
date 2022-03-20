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

    Font font;
    font.loadFromFile("Font.ttf");

    PlaySong q("Реквизиты\\Music\\Menu_Song.ogg");
    q.Play();

    const Color colorArr[6] = { Color::Magenta, Color::Red, Color::Cyan, Color::White, Color::Yellow, Color::Green };

    while (window.isOpen())
    {
        if (scene == 1)
        {
            int i = 1;
            Event event;

            Text txt;
            txt.setFont(font);
            txt.setString(L"------------------------Курсовая работа-------------------------\n.----------Моделирование движения летательного аппарата----------.");
            txt.setCharacterSize(90);
            txt.setOutlineThickness(4.0f);
            txt.setPosition(10, 850);
            txt.setFillColor(Color::Red);

            Text txt2;
            txt2.setFont(font);
            txt2.setString(L"Выберите летательный аппарат");
            txt2.setCharacterSize(90);
            txt2.setOutlineThickness(4.0f);
            txt2.setPosition(550, 700);

            while (window.pollEvent(event))
            {
                if (event.type == Event::KeyPressed)
                    if (event.key.code == Keyboard::Escape)
                        window.close();
            }
            window.clear();
            while (i <= 6)
            {
                Anim q("Реквизиты\\menu\\", i);
                q.go_anim(window);
                txt2.setFillColor(colorArr[i]);
                window.draw(txt);
                window.draw(txt2);
                window.display();
                i++;
            }
        }
    }

    return 0;
}
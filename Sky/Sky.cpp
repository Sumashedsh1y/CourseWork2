#include <SFML/Graphics.hpp>
#include <iostream>
#include "BackDoor.h"
#include "PlaySong.h"
#include "UFO.h"
#include "Anim.h"
#include "GifPng.h"
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
    PlaySong q2("Реквизиты\\Music\\Fly.ogg");

    const Color colorArr[6] = { Color::Magenta, Color::Red, Color::Cyan, Color::White, Color::Yellow, Color::Green };

    int wind = 0;

    int i = 1;
    int w = 1;
    int s = 1;
    UFO ufo1(50, 150);
    while (window.isOpen())
    {
        if (scene == 1)
        {
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
                if (event.type == Event::KeyPressed)
                    if (event.key.code == Keyboard::Enter)
                    {
                        q.Stop();
                        q2.Play();
                        i = 1;
                        scene++;
                        continue;
                    }
            }
            window.clear();

            Anim q("Реквизиты\\menu\\", i);
            q.go_anim(window);
            txt2.setFillColor(colorArr[i]);
            
            
            window.draw(txt);
            window.draw(txt2);
            window.display();
            Sleep(100);
            if (i < 6)
                i++;
            else
                i = 1;

        }
        if (scene == 2)
        {
            Event event;

            while (window.pollEvent(event))
            {
                if (event.type == Event::KeyPressed)
                    if (event.key.code == Keyboard::Escape)
                        window.close();
                if (event.type == Event::KeyPressed)
                    if (event.key.code == Keyboard::Space)
                        wind = 1;
            }
            window.clear();

            Anim r("Реквизиты\\sky\\", i);
            r.go_anim(window);
            Sleep(30);

            ufo1.Move(0.1);
            ufo1.setS(s);
            if (s < 16)
                s++;
            else
                s = 1;

            window.draw(ufo1.ufo());

            if (i < 6)
                i++;
            else
                i = 1;

            if (wind == 1) {
                Png W("Реквизиты\\wind\\", w);
                W.go_anim(window);
                Sleep(1);
                if (w < 29)
                    w++;
                else
                    w = 1;
            }
            window.display();
        }
    }
    return 0;
}
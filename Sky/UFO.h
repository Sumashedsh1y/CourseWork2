#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <format>
#define Pi 3.14
using namespace std;
using namespace sf;
class UFO
{	
public:
	int s = 1, i = 0;
	double x = 50, y = 150;
    int m;

    double l = 16.3;
    double S = 30.0;

    double positionX;
    double positionY;
    double dvX;
    double dvY;
    double aX;
    double aY;
    double liftX,liftY;
    double angle = 0.0;
    double v_phi = 0.0;
    double thrust = 0.0;
    double a_phi = 0.0;
    double SAX = l * l * l / (12.0 * S); // Средняя аэродинамическая хорда крыла 1/2*int(x^2,0,l/2)
    double ro = 1.225; // Плотность воздуха
    double Mz, mz = 0.0, m0 = 0.0;
    double cd = 0.033, cl = 0.02 + cd * cd / Pi; //  cl - коофициэнт подъемной силы, cd - коофициэнт лобового споротивления

	Sprite herosprite;
    Texture herotexture;
	Sprite& Get() {
		return herosprite;
	}

	UFO(int x, int y, int m = 100) : x(x), y(y), m(m)
	{
		string str;
		str = "Реквизиты\\UFO\\" + to_string(s) + ".png";
		herotexture.loadFromFile(str);
		herosprite.setTexture(herotexture);
		herosprite.setPosition(Vector2f(x, y));
        positionX = x;
        positionY = y;
        dvX = 10.0;
        dvY = 0.0;
	}

    void Move(double dt) {

        aX = 0.0;
        aY = 0.0;

        aY += 9.8;

        liftX = -cd * dvX * dvX * ro * S / m;
        liftY = cl * dvX * dvX * ro * S / m;

        aX += liftX * cos(angle / 180.0);
        aY += liftY * sin(-angle/180.0 - Pi / 2.0);

        aX += thrust * 5.0 * cos(angle / 180.0);
        aY += thrust * 5.0 * sin(-angle/180.0 - Pi / 2.0);

        mz = m0 + 0.25 * cd; // Момент тангажа
        Mz = mz * ro * dvX * dvX * S * SAX * 0.5; // Тангаж

        a_phi = Mz / m;
        dvX += aX * dt;
        dvY += aY * dt;
        v_phi = a_phi * dt;

        angle += v_phi * dt;
        positionX += dvX * dt;
        positionY += dvY * dt;

        thrust = 0.0;
        m0 = 0.0;

        herosprite.setRotation(angle);
        herosprite.setPosition(positionX, positionY);
	}

    void WindMove() {
        positionX -= positionX / 100;
    }

	Sprite ufo();
	void setS(int);
};
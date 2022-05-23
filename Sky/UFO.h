#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML/System.hpp>
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
    double angle = 0;
    double v_phi = 0;
    double thrust = 0;
    double a_phi = 0;
    double SAX = l * l * l / (12 * S); // Средняя аэродинамическая хорда крыла 1/2*int(x^2,0,l/2)
    double ro = 1.225;
    double Mz, mz = 0;
    double cd = 0.033, cl = cd + 0.02 + 0.02; //  cl - коофициэнт подъемной силы, cd - коофициэнт лобового споротивления

	Sprite herosprite;Texture herotexture;
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
        dvX = 100;
        dvY = 0;
	}

	void Move(double dt) {

        aX = 0;
        aY = 0;

        aX += m * 9.8 * sin(angle);
        aY += m * 9.8 * cos(angle);
        
        aX -= cd * dvX * dvX * ro * S/m * sin(angle);
        aY -= cl * dvX * dvX * ro * S/m * cos(angle);

        aX += thrust * 100.0 * sin(angle);
        aY += thrust * 100.0 * cos(angle);
        thrust = 0;

        mz = 0.25 * cd;
        Mz = mz * ro * dvX * dvX * S * SAX * 0.5;

        dvX += aX * dt;
        dvY += aY * dt;
        a_phi = Mz * dt;
        v_phi = a_phi * dt;

        angle += v_phi * dt;
        positionX += dvX * dt;
        positionY += dvY * dt;

        herosprite.setRotation(angle);
        herosprite.setPosition(positionX, positionY);
	}

    void WindMove() {
        positionX -= positionX / 100;
    }

	Sprite ufo();
	void setS(int);
};
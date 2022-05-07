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
	float x = 50, y = 150;
    int m;

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
        dvY = +0;
	}

	void Move(double dt) {

        aX = 0;
        aY = 0;

        aY += m * 9.8; // Fdown

        double forwardX = cosf(angle);
        double forwardY = sinf(angle);
        double upX = cosf(angle + Pi / 2);
        double upY = sinf(angle + Pi / 2);
        
        float roS2 = 20.f/m, cd=0.05, cl=0.2; //  cl - коофициэнт подъемной силы, cd - коофициэнт лобового споротивления

        aX -= cd * dvX * dvX * roS2;
        aY -= cl * dvX * dvX * roS2;

        aX += forwardX * thrust * 100.0f;
        aY += forwardY * thrust * 100.0f;
        thrust = 0;

        dvX += aX * dt;
        dvY += aY * dt;
        v_phi += a_phi * dt;

        //v *= exp(-dt); // * frictionCoef); // Сила трения
        //v_phi *= exp(-dt); // * angularFrictionCoef); // Угловое трение

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
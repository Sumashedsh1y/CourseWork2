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

    Vector2f position;
    Vector2f v;
    Vector2f a;
    float angle = 0;
    float v_phi;

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
        position = Vector2f(x, y);
	}

	void Move(float dt) {

        a = Vector2f(0, 0);

        a.y += m * 9.8;

        Vector2f forward = Vector2f(cosf(angle), sinf(angle));
        Vector2f up = Vector2f(cosf(angle + Pi / 2.0f), sinf(angle + Pi / 2.0f));
        float vP = v.x * up.x + v.y * up.y;
        a += -up * vP * vP; // *someCoefficient;

        float thrust = 0;

        a += forward * thrust;

        float a_phi = 0;

        v += a * dt;
        v_phi += a_phi * dt;

        //v *= exp(-dt); // * frictionCoef);
        //v_phi *= exp(-dt); // * angularFrictionCoef);

        angle += a_phi * dt;
        position += v * dt;

        herosprite.setRotation(angle);
        herosprite.setPosition(position);
	}

	Sprite ufo();
	void setS(int);
};
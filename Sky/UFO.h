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
    Vector2f dv;
    Vector2f a;
    float angle = 0;
    float v_phi = 0;
    float thrust = 0;
    float a_phi = 0;

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
        dv.x = 100;
        dv.y = +0;
	}

	void Move(float dt) {

        a = Vector2f(0, 0);

        a.y += m * 9.8; // Fdown

        Vector2f forward = Vector2f(cosf(angle), sinf(angle)); // Fgo
        Vector2f up = Vector2f(cosf(angle + Pi / 2), sinf(angle + Pi / 2)); // Fup
        float vP = dv.x * up.x + dv.y * up.y; // Проекция скорости
        
        
        float rs2 = 20.f/m, cd=0.05, cl=0.2;

        a.x -= cd * dv.x * dv.x * rs2;
        a.y -= cl * dv.x * dv.x * rs2;
        //a -= vP * up; // *someCoefficient;

        a += forward * thrust*100.0f;
        thrust = 0;

        dv += a * dt;
        v_phi += a_phi * dt;

        //v *= exp(-dt); // * frictionCoef); // Сила трения
        //v_phi *= exp(-dt); // * angularFrictionCoef); // Угловое трение

        angle += v_phi * dt;
        position += dv * dt;

        herosprite.setRotation(angle);
        herosprite.setPosition(position);
	}

	Sprite ufo();
	void setS(int);
};
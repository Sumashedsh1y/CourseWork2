#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#define Pi 3.14159265358979323846
using namespace std;
using namespace sf;
class UFO
{	
public:
	Vector2f pos;
	int s = 1;
	double x = 50, y = 150, i=0, phi=0, vx=0, vy=0, omega;
	float v_phi = 0;
	float a_phi = 0;
	Vector2f a;
	Vector2f v;
	Sprite herosprite;Texture herotexture;
	Sprite& Get() {
		return herosprite;
	}

	UFO(int x, int y, int m = 0) : x(x), y(y)
	{
		string str;
		str = "Реквизиты\\UFO\\" + to_string(s) + ".png";
		
		herotexture.loadFromFile(str);
		herosprite.setTexture(herotexture);
		herosprite.setPosition(Vector2f(x, y));
	}

	void Move(float dt) {

		a = Vector2f(0, 0);
		a.y += 1; // типо сила притяжения
		Vector2f forward = Vector2f(cosf(phi), sinf(phi));
		Vector2f up = Vector2f(cosf(phi + Pi / 2.0f), sinf(phi + Pi / 2.0f));
		float Vp = v.x * up.x + v.y * up.y;
		a += -up * (Vp * Vp);

		a += forward;

		v += a * dt;
		v_phi += a_phi * dt;

		v *= exp(-dt);
		v_phi *= exp(-dt);

		phi += v_phi * dt;
		pos += v * dt;

		herosprite.setRotation(phi);
		herosprite.setPosition(pos);
	}

	Sprite ufo();
	void setS(int);
};
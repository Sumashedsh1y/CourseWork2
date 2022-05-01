#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#define Pi 3.14
using namespace std;
using namespace sf;
static float diff(float x)
{
	const float h = 1e-10;
	return ((x + h) - (x - h)) / (2.0f * h);
}
class UFO
{	
public:
	int s = 1, i = 0;
	float x = 50, y = 150;

	float m, phi = 0, vx = 0, vy = 0;
	Vector2f pos;
	float v_phi = 0;
	float a_phi = 0;
	Vector2f a;
	Vector2f dv;
	float thrust = 1;

	Sprite herosprite;Texture herotexture;
	Sprite& Get() {
		return herosprite;
	}

	UFO(int x, int y, int m = 1) : x(x), y(y), m(m)
	{
		string str;
		str = "Реквизиты\\UFO\\" + to_string(s) + ".png";
		herotexture.loadFromFile(str);
		herosprite.setTexture(herotexture);
		herosprite.setPosition(Vector2f(x, y));
	}

	void Move(float dt) {

		a = Vector2f(0, 0);
		a.y += m * 9.8; // Сила гравитации

		Vector2f forward = Vector2f(cosf(phi), sinf(phi));
		Vector2f up = Vector2f(cosf(phi + Pi / 2.0f), sinf(phi + Pi / 2.0f));

		float Vp = dv.x * up.x + dv.y * up.y;
		a -= up * (Vp * Vp);

		a += forward * thrust;

		dv += a * dt; // a = dv / dt
		v_phi += a_phi * dt;

		dv *= exp(-dt);
		v_phi *= exp(-dt);

		phi += v_phi * dt;
		pos += dv * dt;

		herosprite.setRotation(phi);
		herosprite.setPosition(pos);

		a_phi = 0;

	}

	Sprite ufo();
	void setS(int);
};
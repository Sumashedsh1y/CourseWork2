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
	double x = 50, y = 150;

	double vX, vY, m, phi;
	double Fup, Fdown, Fgo, Fstop;

	Sprite herosprite;Texture herotexture;
	Sprite& Get() {
		return herosprite;
	}

	UFO(int x, int y, int v =0, int m = 100, int phi = 0) : x(x), y(y), vX(v), vY(v), m(m), phi(phi)
	{
		string str;
		str = "Реквизиты\\UFO\\" + to_string(s) + ".png";
		herotexture.loadFromFile(str);
		herosprite.setTexture(herotexture);
		herosprite.setPosition(Vector2f(x, y));
	}

	void Move(double dt) {

		Fdown = m * 9.8; // Сила притяжения
		Fup = 0.5 * vY * cos(phi);
		Fstop = 0.5 * vX * cos(phi);
		Fgo = diff(vX * m) / dt;

		vX += Fgo - Fstop;
		vY += Fdown - Fup;

		x += vX * dt;
		y += vY * dt;

		herosprite.setRotation(phi);
		herosprite.setPosition(Vector2f(x, y));
	}

	Sprite ufo();
	void setS(int);
};
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

	double vX, vY, m, phi;
	double Fup, Fdown, Fgo, Fstop;

	Sprite herosprite;Texture herotexture;
	Sprite& Get() {
		return herosprite;
	}

	UFO(int x, int y, int v =0, int m = 1000, int phi = 0) : x(x), y(y), vX(v), vY(v), m(m), phi(phi)
	{
		string str;
		str = "Реквизиты\\UFO\\" + to_string(s) + ".png";
		herotexture.loadFromFile(str);
		herosprite.setTexture(herotexture);
		herosprite.setPosition(Vector2f(x, y));
	}

	void Move(double dt) {

		Fdown = m * 9.8; // g = 9.8
		Fup = 0.5 * 0.033 * 1.2 * vY * vY; // C = 0.033; p = 1.2
		Fstop = 0.5 * (0.34 * 650) / 13 * vX * vX; // K = 0.34; S = 650; X = K*S*v/13
		Fgo = m * vX * dt; // F = m * a = m * dv/dt

		vX += Fgo - Fstop;
		vY += Fdown - Fup;

		x = vX * dt;
		y = vY * dt;

		herosprite.setRotation(phi);
		herosprite.setPosition(Vector2f(x, y));
	}

	Sprite ufo();
	void setS(int);
};
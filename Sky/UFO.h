#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class UFO
{

	
public:
	int s = 1;
	double x = 50, y = 150, i=0, phi=0, vx=0, vy=0, omega;
	Sprite herosprite;Texture herotexture;
	Sprite& Get() {
		return herosprite;
	}

	UFO(int x, int y) : x(x), y(y)
	{
		string str;
		str = "Реквизиты\\UFO\\" + to_string(s) + ".png";
		
		herotexture.loadFromFile(str);
		herosprite.setTexture(herotexture);
		herosprite.setPosition(Vector2f(x, y));
	}

	void Move(double dt) {
		
		vy += 10 * dt;
		vx += 10 * dt;
		
		x += vx * dt;
		y += vy * dt;
		phi += dt;

		herosprite.setPosition(x, y);

		herosprite.setRotation(phi);
		if (y > 300) vy -= 100;



	}

	Sprite ufo();
	void setS(int);
};
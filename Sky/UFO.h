#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class UFO
{
public:
	CircleShape body;
	UFO(int x, int y, float size)
	{
		body.setRadius(size);
		body.setPosition(x, y);
		body.setOutlineThickness(size / 2);
		body.setFillColor(Color::Red);
		body.setOutlineColor(Color::Magenta);
	}
	CircleShape ufo();
};
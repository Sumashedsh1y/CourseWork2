#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class BackDoor
{
	String filename;
	Texture herotexture;
public:
	Sprite herosprite;
	BackDoor() {}
	BackDoor(String file)
	{
		filename = file;
		herotexture.loadFromFile(filename);
		herosprite.setTexture(herotexture);
	}
	Sprite SetBack();
};
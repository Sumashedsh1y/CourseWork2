#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <windows.h>
#include "BackDoor.h"
using namespace std;
using namespace sf;
class Png
{
	string dir;
	int cnt;
public:
	Png(string dir, int cnt)
	{
		this->dir = dir;
		this->cnt = cnt;
	}
	void go_anim(RenderWindow&);
};
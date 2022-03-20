#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <windows.h>
#include "BackDoor.h"
using namespace std;
using namespace sf;
class Anim
{
	string dir;
	int cnt;
public:
	Anim(string dir, int cnt)
	{
		this->dir = dir;
		this->cnt = cnt;
	}
	void go_anim(RenderWindow&);
};
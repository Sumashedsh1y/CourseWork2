#include "GifPng.h"
void Png::go_anim(RenderWindow& win)
{
	string str;
	str = dir + to_string(cnt) + ".png";
	BackDoor q(str);
	win.draw(q.SetBack());
	Sleep(10);
}
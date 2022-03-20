#include "Anim.h"
void Anim::go_anim(RenderWindow& win)
{
	string str;
	str = dir + to_string(cnt) + ".jpg";
	BackDoor q(str);
	win.draw(q.SetBack());
	Sleep(10);
}
#include "Anim.h"
void Anim::go_anim(RenderWindow& win)
{
	string str;
	int i = 1;
	while (i <= cnt)
	{
		str = dir + to_string(i) + ".jpg";
		BackDoor q(str);
		win.draw(q.SetBack());
		win.display();
		Sleep(100);
		i++;
	}
}
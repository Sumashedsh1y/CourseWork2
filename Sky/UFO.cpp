#include "UFO.h"
Sprite UFO::ufo()
{
	return herosprite;
}
void UFO::setS(int s)
{
	this->s = s;
	string str;
	str = "Реквизиты\\UFO\\" + to_string(s) + ".png";
	herotexture.loadFromFile(str);
	herosprite.setTexture(herotexture);
}
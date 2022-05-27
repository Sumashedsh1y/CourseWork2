#include "UFO.h"
UFO::UFO(int x, int y, int m) : x(x), y(y), m(m)
{
    string str;
    str = "Реквизиты\\UFO\\" + to_string(s) + ".png";
    herotexture.loadFromFile(str);
    herosprite.setTexture(herotexture);
    herosprite.setPosition(Vector2f(x, y));
    positionX = x;
    positionY = y;
    dvX = 18.8;
    dvY = 0.0;
}
void UFO::Move(double dt) {

    aX = 0.0;
    aY = 0.0;

    aY += 9.8;

    liftX = -cd * dvX * dvX * ro * S * 0.5 / m;
    liftY = cl * dvX * dvX * ro * S * 0.5 / m;

    aX += liftX * cos(angle / 180.0);
    aY += liftY * sin(-angle / 180.0 - Pi / 2.0);

    aX += thrust * 5.0 * cos(angle / 180.0);
    aY += thrust * 5.0 * sin(-angle / 180.0 - Pi / 2.0);

    mz = m0 + 0.25 * cd; // Момент тангажа
    Mz = mz * ro * dvX * dvX * S * SAX * 0.5; // Тангаж

    a_phi = Mz / m;
    dvX += aX * dt;
    dvY += aY * dt;
    v_phi = a_phi * dt;

    angle += v_phi * dt;
    positionX += dvX * dt;
    positionY += dvY * dt;

    thrust = 0.0;
    m0 = 0.0;
    cd = 0.033;
    cl = 0.02 + 0.033 * 0.033 / Pi;

    herosprite.setRotation(angle);
    herosprite.setPosition(positionX, positionY);
}
void UFO::WindMove() {

	cd *= 3;
    cl *= 3;

}
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
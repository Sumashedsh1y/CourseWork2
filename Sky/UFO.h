#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <SFML/System.hpp>
#include <format>
#define Pi 3.14
using namespace std;
using namespace sf;
class UFO
{	
public:
	int s = 1, i = 0;
	double x = 50, y = 150;
    int m;

    double l = 16.3;
    double S = 30.0;

    double dt = 0;
    double positionX;
    double positionY;
    double dvX;
    double dvY;
    double aX;
    double aY;
    double liftX,liftY;
    double angle = 0.0;
    double v_phi = 0.0;
    double thrust = 1.0;
    double a_phi = 0.0;
    double SAX = l * l * l / (12.0 * S); // Средняя аэродинамическая хорда крыла 1/2*int(x^2,0,l/2)
    double ro = 1.225; // Плотность воздуха
    double Mz, mz = 0.0, m0 = 0.0;
    double cd = 0.033, cl = 0.02 + cd * cd / Pi; //  cl - коофициэнт подъемной силы, cd - коофициэнт лобового споротивления

	Sprite herosprite;
    Texture herotexture;
	Sprite& Get() {
		return herosprite;
	}

    UFO(int x, int y, int m = 2000);

    void Move(double dt);

    void WindMove();

	Sprite ufo();
	void setS(int);
};
#pragma once
#include <iostream>
#include <fstream>
#include "UFO.h"
using namespace std;
class Plot
{
	ofstream file;
public:
	Plot() {
		file.open("Plot.txt");
	}
	void Save(UFO&);
};
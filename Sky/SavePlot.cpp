#include "SavePlot.h"
void Plot::Save(UFO& ufo)
{
    setlocale(LC_ALL, "Russian");
    file << ufo.positionX << "\t" << ufo.positionY << endl;
}

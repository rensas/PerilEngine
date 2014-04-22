#include "Point.h"
#include <iostream>

Point::Point(int nx, int ny, int nz) {
  setLocation(nx, ny, nz);
}

void Point::setLocation(int nx, int ny, int nz) {
    x = nx;
    y = ny;
    z = nz;
}

void Point::printCoords(){
  std::cout<<"X: "<<x<<", Y: "<<y<<", Z: "<<z<<"\n";
}

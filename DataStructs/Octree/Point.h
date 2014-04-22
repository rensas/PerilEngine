#ifndef POINT_H
#define POINT_H

class Point {

 private:
  int x;
  int y;
  int z;
  
  Point() { }

 public:
  Point(int nx, int ny, int nz);

  int getX() { return x; }
  int getY() { return y; }
  int getZ() { return z; }

  void setLocation(int nx, int ny, int nz);

  void printCoords();
};

#endif

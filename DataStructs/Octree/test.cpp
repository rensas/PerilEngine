#include <iostream>
#include <unistd.h>
#include "Point.h"
#include "Octnode.h"
#include "Octree.h"

void leafStatus(bool b) {
  if(b > 0){
    std::cout<<"This is a leaf node. "<<b<<"\n";
  } else {
    std::cout<<"This is NOT a leaf node. "<<b<<"\n";
  }
}


int main(int argc, char* argv[]) {

  Point *a = new Point(1, 2, 3);

  int new_x = a->getX();

  std::cout<<"This is new_x: " <<new_x<<std::endl;
  
  Point b(0,0,0);
  b.setLocation(4, 5, 6);
  
  std::cout<<"This is new_x: " <<b.getX()<<std::endl;

  b.printCoords();

  Octnode n(b, 15);

  n.getMidpoint()->printCoords();

  leafStatus(n.checkIfLeaf());

  Octnode n2(*a, 8);
  n2.getMidpoint()->printCoords();
    leafStatus(n2.checkIfLeaf());
  delete(a);


  Point c(1, 1, 1);
  Point d(-1, -1, -1);
  Octree *o = new Octree(1024);
  
  o->insertNode(c);
  o->insertNode(d);
  /*
  int numProc;
  numProc = sysconf( _SC_NPROCESSORS_ONLN );
  std::cout<<"Number of system processors: "<<numProc<<"\n";
  */

 return 0;
}

#ifndef OCTNODE_H
#define OCTNODE_H

#include "Point.h"
#include "../../GlobalDefinitions.h"
#include <cstddef>
class Octnode {

 private:
  //Main components of any Octnode
  Point *mid_point;
  double box_radius;  //Determined on creation by parent's radius
  bool isLeafNode;
  Point *dataPoint;

  //Child node pointers if not a leaf node
  Octnode *child_1;
  Octnode *child_2;
  Octnode *child_3;
  Octnode *child_4;
  Octnode *child_5;
  Octnode *child_6;
  Octnode *child_7;
  Octnode *child_8;

  // Parent node
  Octnode *parent;
  
 public:
  Octnode(Point p, double radius);
  ~Octnode(){ delete(mid_point); }
  //Getters
  Point *getMidpoint() { return mid_point; }
  double getRadius() { return box_radius; } 
  Octnode *getChild1() { return child_1; }
  Octnode *getChild2() { return child_2; }
  Octnode *getChild3() { return child_3; }
  Octnode *getChild4() { return child_4; }
  Octnode *getChild5() { return child_5; }
  Octnode *getChild6() { return child_6; }
  Octnode *getChild7() { return child_7; }
  Octnode *getChild8() { return child_8; }

  void setChild1(Octnode *n);
  void setChild2(Octnode *n);
  void setChild3(Octnode *n);
  void setChild4(Octnode *n);
  void setChild5(Octnode *n);
  void setChild6(Octnode *n);
  void setChild7(Octnode *n);
  void setChild8(Octnode *n);
  bool checkIfLeaf(){ return isLeafNode; }
  void setDataPoint(Point p);
};

#endif

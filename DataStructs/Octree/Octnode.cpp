
#include "Octnode.h"

Octnode::Octnode(Point p, double radius) {
  
  // Set up the node, and check if it is a leaf
  mid_point = new Point(p.getX(), p.getY(), p.getZ());
  box_radius = radius;
  if(box_radius <= LEAF_SIZE){
    isLeafNode = 1;
  }  else {
    isLeafNode = 0;
  }
  
  child_1 = NULL;
  child_2 = NULL;
  child_3 = NULL;
  child_4 = NULL;
  child_5 = NULL;
  child_6 = NULL;
  child_7 = NULL;
  child_8 = NULL;

}

// Setters
void Octnode::setChild1(Octnode *n) {
  child_1 = n;
}
void Octnode::setChild2(Octnode *n) {
  child_2 = n;
}
void Octnode::setChild3(Octnode *n) {
  child_3 = n;
}
void Octnode::setChild4(Octnode *n) {
  child_4 = n;
}
void Octnode::setChild5(Octnode *n) {
  child_5 = n;
}
void Octnode::setChild6(Octnode *n) {
  child_6 = n;
}
void Octnode::setChild7(Octnode *n) {
  child_7 = n;
}
void Octnode::setChild8(Octnode *n) {
  child_8 = n;
}
void Octnode::setDataPoint(Point p){
  dataPoint = new Point(p.getX(), p.getY(), p.getZ());
}

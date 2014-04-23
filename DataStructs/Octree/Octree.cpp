/* 

   Child node numbering definition:

   1 = +X, +Y, +Z
   2 = -X, +Y, +Z
   3 = -X, +Y, -Z
   4 = +X, +Y, -Z
   5 = +X, -Y, +Z
   6 = -X, -Y, +Z
   7 = -X, -Y, -Z
   8 = +X, -Y, -Z
   

*/



#include <iostream>
#include <bitset>
#include "Octree.h"


Octree::Octree(int radius) {

  world_radius = radius;
  root = NULL;
  
}

Octree::~Octree(){
  //Delete all nodes
}

void Octree::insertNode(Point p){
  if(root!=NULL){
    insertNode(p, root);
  } else {
    Point np(0,0,0);
    root = new Octnode(np, world_radius);
    root->setDataPoint(p);
    std::cout<<"Created root node\n";
  }
}

void Octree::insertNode(Point p, Octnode *n){
  //Check if this node's dataPoint is set. if it isn't, assign it with p.
  //If it is, check which new child dataPoint belongs in, create it, and assign it

  double childRadius = (n->getRadius())/4;
  short childNumber = 0;

  Point *pmp = n->getMidpoint();

  /* START IF BLOCK */
  if(p.getX() > pmp->getX()) {      // +X 
    if(p.getY() > pmp->getY()) {    // +X +Y
      if(p.getZ() > pmp->getZ()) {  // +X +Y +Z *
	childNumber=1;
      } else {                    // +X +Y -Z *
	childNumber=4;
      }
    } else {                      // +X -Y
      if(p.getZ() > pmp->getZ()) {  // +X -Y +Z *
	childNumber=5;
      } else {                    // +X -Y -Z *
	childNumber=8;
      }
    }
  } else {                        // -X
    if(p.getY() > pmp->getY()) {    // -X +Y
      if(p.getZ() > pmp->getZ()) {  // -X +Y +Z *
	childNumber=2;
      } else {                    // -X +Y -Z *
	childNumber=3;
      }
    } else {
      if(p.getZ() > pmp->getZ()) {  // -X -Y +Z *
	childNumber=6;
      } else {                    // -X -Y -Z *
	childNumber=7;
      }
    }
  }
  /* END IF BLOCK */
  std::cout<<"Child number is: "<<childNumber<<"\n";
}

short Octree::whichChild(Point parent, Point test){

  short childno = -1;
  std::bitset<3> bits;

  if(test.getX() > parent.getX()) bits.set(0);
  if(test.getY() > parent.getY()) bits.set(1);
  if(test.getZ() > parent.getZ()) bits.set(2);
  
  return bits.to_ulong();
}

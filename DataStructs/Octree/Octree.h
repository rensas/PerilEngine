#ifndef OCTREE_H
#define OCTREE_H

#include "Octnode.h"
#include "Point.h"

class Octree {

 private:
  int world_radius;
  short tree_depth;
  

  //Root node of the tree
  Octnode *root;
  
  //Private Default Constructor
  Octree() {}
  
  void insertNode(Point p, Octnode *n);

 public:
  
  Octree(int radius);
  ~Octree();
  int getWorldRadius(){ return world_radius; }
  //Octnode *getRootNode() { return root; }
  //short getOctantForPoint(const Point p); 

  void insertNode(Point p);
  //Octnode *addNodeForPoint(const Point p);  
  //void addObjectToTree(Object o);

  short whichChild(Point parent, Point test);

};

#endif

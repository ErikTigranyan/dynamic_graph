#include "include/DynamicGraph.h"


void DynamicGraph::crossroad_removed(int v){
  g.remove_crossroad(v);
}

void DynamicGraph::crossroad_added(int v){
  g.add_crossroad(v);
}


void DynamicGraph::street_removed(int u, int v){
  g.remove_street(u, v);
}

void DynamicGraph::street_added(int u, int v, std::size_t length){
  g.add_street(u,v, length);
}
#include "include/DynamicGraph.h"


void DynamicGraph::crossroad_removed(int v){
  g.remove_crossroad(v);
}

void DynamicGraph::crossroad_added(int v){
  g.add_crossroad(v);
}

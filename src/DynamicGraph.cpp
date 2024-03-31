#include "include/DynamicGraph.h"
#include <stdexcept>

void DynamicGraph::initialize(){
  g.initialize();
  dj = Dijikstra(g);
}

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

std::size_t DynamicGraph::sp_length(int u, int v){
  int dst = dj.distance(u, v).first;
  if (dst == INF){
    std::cout << "There is no path for given vertexes" << std::endl;
    return -1;
  }
  return dst;
}
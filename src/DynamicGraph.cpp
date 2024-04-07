#include "include/DynamicGraph.h"
#include <stdexcept>

void DynamicGraph::initialize(){
  g.initialize();
  dj = Dijikstra(g);
}

void DynamicGraph::crossroad_removed(int v){
  g.remove_crossroad(v);
  dj.g.remove_crossroad(v);
}

void DynamicGraph::crossroad_added(int v){
  g.add_crossroad(v);
  dj.g.add_crossroad(v);
}


void DynamicGraph::street_removed(int u, int v){
  g.remove_street(u, v);
  dj.g.remove_street(u, v);
}

void DynamicGraph::street_added(int u, int v, std::size_t length){
  g.add_street(u,v, length);
  dj.g.add_street(u, v, length);
}

std::size_t DynamicGraph::sp_length(int u, int v){
  int dst = dj.distance(u, v).first;
  if (dst == INF){
    std::cout << "There is no path for given vertexes" << std::endl;
    return -1;
  }
  return dst;
}

std::vector<int>  DynamicGraph::sp_route(int u, int v){
  if(dj.inter.get_path(u, v) != std::nullopt){
    std::cout << "GET PATH FROM SAVED PATHS" << std::endl;
    return dj.inter.get_path(u, v).value() ;
  }

  int dst = dj.distance(u, v).first;
  std::vector<int> path = dj.distance(u, v).second;
  if (dst == INF){
    std::cout << "There is no path for given vertexes" << std::endl;
    return std::vector<int>();
  }
  return path;
}
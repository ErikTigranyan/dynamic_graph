#pragma once
#include <iostream>
#include <vector>
#include "Graph.h"

// Class for delegating requests
class DynamicGraph {
  public:
    Graph g;

    DynamicGraph(std::size_t num) : g(num){}

    std::size_t       sp_length(int u, int v);
    std::vector<int>  sp_route(int u, int v);
    void              street_added(int u, int v, std::size_t length);
    void              street_removed(int u, int v);
    void              crossroad_added(int v);
    void              crossroad_removed(int v);
    void              construction_started(){g.active=1;};
    void              construction_finished(){g.active = 0;}
};
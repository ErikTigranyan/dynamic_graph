#pragma once
#include <iostream>
#include <vector>
#include "Graph.h"

// Class for delegating requests
class DynamicGraph {
  private:
    // graph

  public:
    std::size_t       sp_length(int u, int v);
    std::vector<int>  sp_route(int u, int v);
    void              construction_started();   // TODO: Understand what this should do
    void              street_added(int u, int v, std::size_t length);
    void              street_removed(int u, int v);
    void              crossroad_added(int v);
    void              crossroad_removed(int v);
    void              construction_finished();  // TODO: Understand what this should do

};
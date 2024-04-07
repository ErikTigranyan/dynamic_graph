#include "src/include/DynamicGraph.h"
#include <iostream>


int main() {
  DynamicGraph g(6);                          // Fix when size is 0;
  // g.crossroad_added(0);
  // g.crossroad_added(1);
  // g.crossroad_added(2);
  // g.crossroad_added(3);
  // g.crossroad_added(4);
  g.initialize(); 
  // g.construction_finished();
  // g.crossroad_added(5);                    // Does not work
  // g.street_added(3, 5, 4);                 // Does not work
  // g.street_added(1, 2, 1);
  // g.street_added(2, 3, 1);
  // g.street_added(0, 3, 15);
  // g.street_added(3, 5, 4);
  // g.street_added(4, 3, 30);
  // g.dj.g.self_print();

  // g.street_removed(2, 3);
  // std::cout << g.sp_length(0, 2) << std::endl; // Works
  // std::vector<int> path = g.sp_route(0, 4);    // Works
  std::vector<int> asdf = g.sp_route(0, 3);    // Prints path 0, 4 even though there is no one
  std::vector<int> agljk = g.sp_route(1, 2);
  for(int i=0;i<agljk.size();i++) {
    std::cout << agljk[i] << " ";
  }
  return 0;
}



/*
5 5
0 1 2
1 2 1
2 3 1
0 3 15
4 3 10
*/
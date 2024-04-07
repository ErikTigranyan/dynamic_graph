#include "src/include/DynamicGraph.h"
#include <iostream>


int main() {
  DynamicGraph g;
  g.crossroad_added(0);
  g.crossroad_added(1);
  g.crossroad_added(2);
  g.crossroad_added(3);
  g.crossroad_added(4);

  g.construction_finished();
  g.street_added(0, 1, 2);
  g.street_added(1, 2, 1);
  g.street_added(2, 3, 1);
  g.street_added(0, 3, 15);
  g.street_added(4, 3, 10);
  


  std::vector<int> agljk = g.sp_route(1, 3);
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
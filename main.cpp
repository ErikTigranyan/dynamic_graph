#include "src/include/DynamicGraph.h"
#include <iostream>


int main() {
  DynamicGraph g(6);
  g.crossroad_added(0);
  g.crossroad_added(1);
  g.crossroad_added(2);
  g.crossroad_added(3);
  g.crossroad_added(4);
  g.crossroad_added(5);

  g.street_added(0, 1, 2);
  g.street_added(1, 2, 1);
  g.street_added(2, 3, 1);
  g.street_added(0, 3, 15);
  g.street_added(3, 5, 4);
  g.street_added(4, 3, 30);
  g.dj.g.self_print();

  g.street_removed(2, 3);
  std::cout << g.sp_length(0, 3) << std::endl;

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
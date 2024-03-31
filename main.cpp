#include "src/include/DynamicGraph.h"
#include <iostream>


int main() {
  DynamicGraph g(3);
  g.crossroad_added(0);
  g.crossroad_added(3);
  g.crossroad_added(2);
  g.initialize();
  std::cout << "INITIALIZED \n \n " << std::endl;
  g.print();

  return 0;
}


#include "src/include/DynamicGraph.h"
#include <iostream>


int main() {
  Graph g(10);
  std::cout << "TEST " << g.get()[5][4] << std::endl;

  return 0;
}
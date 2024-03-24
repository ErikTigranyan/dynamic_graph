#include "src/include/DynamicGraph.h"
#include <iostream>


int main() {
  DynamicGraph g(10);
  std::cout << "TEST " << g.g[5][4] << std::endl;
  return 0;
}
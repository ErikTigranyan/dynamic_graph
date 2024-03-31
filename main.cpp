#include "src/include/DynamicGraph.h"
#include <iostream>


int main() {
  DynamicGraph g(5);
  g.initialize();
  g.print();
  std::cout << "INITIALIZED \n \n " << std::endl;
  g.sp_length(0, 4);

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
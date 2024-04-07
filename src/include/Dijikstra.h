#include <vector>
#include <queue>
#include "Graph.h"
#include "IntermediatePaths.h"


class Dijikstra{
  public:
  Graph g;
  IntermediatePaths inter;
  public:
  Dijikstra(){};
  Dijikstra(Graph g_) : g(g_){}


  std::size_t distances(int u);
  std::pair<int, std::vector<int>> distance(int v, int dest);
};
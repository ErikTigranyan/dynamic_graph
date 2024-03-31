#include <vector>
#include <queue>
#include "Graph.h"
#include "IntermediatePaths.h"


class Dijikstra{
  Graph g;
  IntermediatePaths inter;
  // void dfs
  public:

  Dijikstra(Graph g_) : g(g_){}


  std::size_t distance(int u, int v);
  std::vector<std::size_t> distances(int v);
};
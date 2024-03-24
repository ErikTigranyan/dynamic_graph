#include <vector>
#include <queue>
#include <stack>
#include "Graph.h"


class Dijikstra{
  Graph g;
  IntermediatePaths inter;
  // void dfs
  public:

  Dijikstra(Graph g_) : g(g_){}


  std::size_t distance(int u, int v);
  std::vector<std::size_t> distances(int v);

}
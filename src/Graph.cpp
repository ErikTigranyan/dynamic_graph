#include "include/Graph.h"


Graph::Graph(const Graph& other){
  g = other.g;
}

void Graph::remove_crossroad(int v){
  active_crossroads[v] = false;
}

void Graph::add_crossroad(int v){
  std::vector<int> new_c(size, 0);
  g.insert(g.begin() + v, new_c);
}


void Graph::self_print(){
  for(int i=0;i<size;i++) {
    for(int j=0;j<size;j++) {
      std::cout << g[i][j] << " ";
    }
    std::cout << "\n";
  }
}


void Graph::initialize() {
  int n, m;
  std::cin >> n >> m;
  for(int i=0;i<m;i++){
      int u, v, l;
      std::cin >> u >> v >> l;
      g[u][v] = l; 
    }
  }

void Graph::add_street(int u, int v, std::size_t length){
  g[u][v] = length;
}

void Graph::remove_street(int u, int v){
  g[u][v] = INF;
}
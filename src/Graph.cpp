#include "include/Graph.h"


Graph::Graph(const Graph& other){
  g = other.g;
  size = other.size;
  active_crossroads = other.active_crossroads;
  active = other.active;
}

void Graph::remove_crossroad(int v){
  if(!active){
    std::cout << "WARNING: construction is not started!" << std::endl;
    return;
  }
  active_crossroads[v] = false;
}

void Graph::add_crossroad(int v){
  if(!active){
    std::cout << "WARNING: construction is not started!" << std::endl;
    return;
  }
  
  size++;
  std::vector<int> new_c(size, INF);
  g.push_back(new_c);

  for(int i=0;i<g.size();i++) {
    g[i].push_back(INF);
  }

  g[size-1][size-1] = 0;
  active_crossroads.push_back(true);
}


void Graph::self_print(){
  for(int i=0;i<size;i++) {
      for(int j=0; j < size;j++) {
          if(active_crossroads[j] && active_crossroads[i])
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
  if(!active){
    std::cout << "ERROR: construction is finished!" << std::endl;
    return;
  }
  if(u > size || v > size){
    std::cout << "ERROR: No such crossroad" << std::endl;
    return;
  }

  g[u][v] = length;
}

void Graph::remove_street(int u, int v){
  g[u][v] = INF;
}
#include "include/Dijikstra.h"


// std::vector<std::size_t> Dijikstra::distances(int v){
//     int vertices = g.size(); 
//     std::vector<std::size_t> dist(vertices, INF);  
//     std::vector<bool> visited(vertices, false);  
 
     
//     std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq; 
 
     
//     dist[v] = 0; 
//     pq.push({0, v}); 
 
     
//     while (!pq.empty()) { 
//         int u = pq.top().second; 
//         pq.pop(); 
 
//         if (visited[u]) 
//             continue; 
 
//         visited[u] = true; 
 
         
//         for (int v = 0; v < vertices; ++v) { 
//             if (!visited[v] && g[u][v] && dist[u] != INF && dist[u] + g[u][v] < dist[v]) { 
//                 dist[v] = dist[u] + g[u][v]; 
//                 pq.push({dist[v], v}); 
//             } 
//         } 
//     } 
 
     
//     std::cout << "Vertex \t Distance from Source" << std::endl; 
//     for (int i = 0; i < vertices; ++i) 
//         std::cout << i << "\t\t" << dist[i] << std::endl; 

//     return dist;
// }


std::vector<std::size_t> Dijikstra::distances(int u){
  std::vector<std::size_t> d(g.size, INF);
  std::vector<int> used(g.size, 0);

  for(int v;v<g.size;v++){

  }

  d[u] = 0;
  while(true){

    for(int i=0;i<g.size;i++){
      if(!used[i] && (u == -1 || d[u] > d[i])){

      }
    }
  }
  return d;
}
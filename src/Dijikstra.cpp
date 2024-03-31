#include "include/Dijikstra.h"


std::vector<int> backtrack(std::vector<std::size_t> previous, int source, int sink){
    std::vector<int> path;

    // If the source is not in the previous array, return empty path
    if (previous[source] == -1)
        return path;

    int V = sink; // Path is reconstructed backwards

    path.push_back(V); // Start with the sink vertex

    // Reconstruct the path backwards until we reach the source vertex
    while (V != source) {
        V = previous[V]; // Move to the previous node in the path
        path.insert(path.begin(), V); // Insert the previous node at the beginning of the path
    }

    return path;
}




std::pair<int, std::vector<int>> Dijikstra::distance(int v, int dest) {
    int vertices = g.size; 
    std::vector<std::size_t> dist(vertices, INF);  
    std::vector<bool> visited(vertices, false);  
    std::vector<std::size_t> path(g.size);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq; 

    dist[v] = 0; 
    pq.push({0, v}); 

    while (!pq.empty()) { 
        int u = pq.top().second; 
        pq.pop(); 

        if (visited[u]) 
            continue; 

        visited[u] = true; 
        if(u == dest)
          break;
        // Traverse only outgoing edges from vertex u
        for (int v = 0; v < vertices; ++v) { 
            if (!visited[v] && g[u][v] != INF && dist[u] != INF ) { 
                if(dist[u] + g[u][v] < dist[v]){
                  dist[v] = dist[u] + g[u][v]; 
                  pq.push({dist[v], v}); 
                  path[v] = u;
                }
            } 
        }
    } 
    if(dest > 0){
      std::vector<int> back = backtrack(path, v, dest);
      return std::make_pair(dist[dest], back);
    }

}


#include "include/Dijikstra.h"

#include <unordered_set>

std::vector<int> backtrack(const std::vector<int>& previous, int source, int sink) {
    std::vector<int> path;

    if (previous[sink] == INF)
        return path;

    int V = sink;
    std::unordered_set<int> visited;

    while (V != source) {

        if (visited.find(V) != visited.end())
            break;

        visited.insert(V); 
        path.insert(path.begin(), V); 
        V = previous[V]; 
    }

    if (V == source)
        path.insert(path.begin(), source); 

    return path;
}

std::pair<int, std::vector<int>> Dijikstra::distance(int v, int dest) {
    int vertices = g.size; 
    std::vector<std::size_t> dist(vertices, INF);  
    std::vector<bool> visited(vertices, false);  
    std::vector<int> previous(vertices, -1); 

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

        for (int v = 0; v < vertices; ++v) { 
            if(!g.active_crossroads[v])
                continue;

            if (!visited[v] && g[u][v] != INF && dist[u] != INF ) { 
                if(dist[u] + g[u][v] < dist[v]){
                    dist[v] = dist[u] + g[u][v]; 
                    pq.push({dist[v], v}); 
                    previous[v] = u; 
                }
            } 
        }
    } 

    // Update intermediate paths
    for(int n = 0; n < dest; ++n){
        for (int i = 0; i < dest; ++i) {
            if (i != n && i != dest && previous[i] != -1) {

                std::vector<int> path = backtrack(previous, n, i);
                inter.add_path(std::make_pair(n, i), path);
            }
        }
    }

    std::vector<int> destPath = backtrack(previous, v, dest);
    inter.add_path(std::make_pair(v, dest), destPath); 

    return std::make_pair(dist[dest], destPath);
}

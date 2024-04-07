#include "include/Dijikstra.h"

#include <unordered_set>

std::vector<int> backtrack(const std::vector<int>& previous, int source, int sink) {
    std::vector<int> path;

    // If the source is not in the previous array or sink is unreachable, return empty path
    if (previous[sink] == -1)
        return path;

    int V = sink; // Path is reconstructed backwards
    std::unordered_set<int> visited; // To keep track of visited vertices

    while (V != source) {
        // If we encounter a vertex that has been visited before, break the loop to avoid infinite loop
        if (visited.find(V) != visited.end())
            break;

        visited.insert(V); // Mark vertex as visited
        path.insert(path.begin(), V); // Insert the previous node at the beginning of the path
        V = previous[V]; // Move to the previous node in the path
    }

    // Check if source is reachable from sink
    if (V == source)
        path.insert(path.begin(), source); // Insert the source node

    return path;
}

std::pair<int, std::vector<int>> Dijikstra::distance(int v, int dest) {
    int vertices = g.size; 
    std::vector<std::size_t> dist(vertices, INF);  
    std::vector<bool> visited(vertices, false);  
    std::vector<int> previous(vertices, -1); // Previous vertex for each vertex
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
                    previous[v] = u; // Update previous vertex for vertex v


                }
            } 
        }
    } 

    for(int n = 0; n < dest; ++n){
        for (int i = 0; i < dest; ++i) {
            if (i != n && i != dest && previous[i] != -1) {
                std::vector<int> path = backtrack(previous, n, i);
                inter.add_path(std::make_pair(n, i), path);
            }
        }
    }

    std::vector<int> destPath = backtrack(previous, v, dest);
    inter.add_path(std::make_pair(v, dest), destPath); // Update path for destination vertex

    return std::make_pair(dist[dest], destPath);
}

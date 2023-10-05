//Dijkstra's algorithm is an algorithm for finding the shortest paths between nodes in a graph, which may represent, for example, road networks. It was conceived by computer scientist Edsger W. Dijkstra in 1956 and published three years later.

/*    The selectMinDistance function selects the vertex with the smallest distance that hasn't been processed yet.
    The main dijkstra function constructs the shortest path tree. It initializes distances and sets the source vertex distance to 0. It then selects vertices one by one and updates the distance values of adjacent vertices.
    The example graph in the main function is an adjacency matrix where graph[i][j] is the weight of the edge between vertices i and j, or 0 if there is no edge. Adjust this matrix as needed to test with different graphs.*/

#include<iostream>
#include<vector>
#include<climits>

// Number of vertices in the graph
#define V 5

// Utility function to find the vertex with the minimum distance value
// from the set of vertices not yet included in the shortest path tree
int selectMinDistance(const std::vector<int> &dist, const std::vector<bool> &sptSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Dijkstra's algorithm
void dijkstra(const std::vector<std::vector<int>> &graph, int src) {
    std::vector<int> dist(V, INT_MAX); // The output array. dist[i] will hold the shortest
                                      // distance from src to i
    dist[src] = 0; // Distance of source vertex from itself is always 0

    std::vector<bool> sptSet(V, false); // sptSet[i] will be true if vertex i is included in
                                        // shortest path tree or shortest distance from src to i is finalized

    for (int count = 0; count < V - 1; count++) {
        int u = selectMinDistance(dist, sptSet); // Pick the minimum distance vertex from the
                                                 // set of vertices not yet included in shortest path tree

        sptSet[u] = true; // Mark the picked vertex as included

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    // Print the constructed distance array
    for (int i = 0; i < V; i++)
        std::cout << "Distance from source to vertex " << i << " is: " << dist[i] << std::endl;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {0, 9, 6, 5, 3},
        {9, 0, 0, 0, 0},
        {6, 0, 0, 0, 0},
        {5, 0, 0, 0, 0},
        {3, 0, 0, 0, 0}
    };

    dijkstra(graph, 0);

    return 0;
}

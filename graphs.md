Graphs in C++

Introduction:

A graph is one of the most fundamental and versatile data structures used in the field of computer science. It consists of a finite set of nodes (or vertices) and a set of edges that connect these nodes. Each edge connects two nodes, representing a relationship between them. Depending on the nature of the relationship, a graph can be undirected (where an edge doesn't have a direction) or directed (where an edge has a start and an end vertex, often called a "digraph").

Number of edges:
    
        Undirected Graph: m <= n(n-1)/2
        Directed Graph: m <= n(n-1)
    
    where n is the number of vertices and m is the number of edges in the graph.
    *Assuming no self-loops and no multiple edges.

    Dense --> too many edges (We typically use adjacency matrix representation for dense graphs)
    Sparse --> too few edges (We typically use adjacency list representation for sparse graphs)

Path: A sequence (walk) of vertices in a graph such that all vertices in the path are connected by edges.
Trail: A walk in which no edges are repeated.

Simple Path: A path in which no vertices (and thus no edges) are repeated.
Walk: Similar to a path, except that vertices and edges can be repeated.

Strongly Connected Graph: A directed graph in which there is a path from each vertex to every other vertex.
Connected Graph: An undirected graph in which there is a path from each vertex to every other vertex.

Weakly Connected Graph: A directed graph in which there is a path from each vertex to every other vertex if we ignore the direction of edges.

Closed Walk: A walk in which the start vertex and end vertex are the same.

Simple Cycle: A cycle in which no vertices (and thus no edges) are repeated, except the start and end vertex.

Acyclic Graph: A graph that has no cycles. For example, a tree is an acyclic connected graph.

How to represent Graphs?:
    
        Adjacency Matrix: A 2D array of size V x V, where V is the number of vertices in a graph. If there is an edge from vertex i to vertex j, then the cell M[i][j] is 1, otherwise 0. For undirected graphs, since an edge from vertex i to vertex j is the same as an edge from vertex j to vertex i, we have M[i][j] = M[j][i] = 1. Time complexity for finding adjacent vertices is O(V), where V is the number of vertices in the graph. Also time complexity for finding if there is an edge from vertex i to vertex j is O(1) + O(V), if we use hash tables we can avoid the O(V) time complexity. so overall time complexity is O(1).There is a big space-time tradeoff here. Adjacency matrix is good if the graph is dense, i.e. the number of edges is close to the number of vertices squared. Otherwise, it's better to use an adjacency list.
    
        Adjacency List: An array of linked lists, where the size of the array is equal to the number of vertices in a graph. Each entry in the array represents a vertex and the linked list in each entry represents the other vertices that form an edge with the vertex.
    
        Edge List: A list of all the edges in the graph. Each edge is represented by a pair of vertices.
    
        Incidence Matrix: A 2D array of size V x E, where V is the number of vertices and E is the number of edges in a graph. If edge e is incident on vertex v, then M[v][e] = 1, otherwise 0. For undirected graphs, since an edge incident on vertex v is the same as an edge incident on vertex v, we have M[v][e] = 1.


Where Are Graphs Used?

Graphs are ubiquitous and find applications in various domains:

    Social Networks: Representing people as nodes and their friendships/connections as edges.
    Web Crawlers: Representing web pages as nodes and hyperlinks as edges.
    Transport Networks: Cities can be nodes, with roads/railways as edges.
    Dependency Trees: For example, in software packages where one package might depend on others.
    Biology: Representing networks of ecological relationships or pathways in cellular systems.

... and many more.
Types of Graphs:

    Undirected Graph: Edges do not have a direction.
    Directed Graph (Digraph): Edges have a direction.
    Weighted Graph: Edges have weights or costs associated with them.
    Unweighted Graph: Edges do not have any weight.
    Cyclic Graph: Contains at least one cycle.
    Acyclic Graph: Does not contain any cycles. A special type is the "Directed Acyclic Graph" (DAG).

Common Graph Algorithms:

    Traversal Algorithms:
        Depth First Search (DFS)
        Breadth First Search (BFS)

    Shortest Path Algorithms:
        Dijkstra's Algorithm (for weighted graphs)
        Bellman-Ford Algorithm
        Floyd-Warshall Algorithm

    Minimum Spanning Tree Algorithms:
        Kruskal's Algorithm
        Prim's Algorithm

    Cycle Detection Algorithms:
        Using DFS
        Union-Find method for undirected graphs

    Topological Sort (specifically for DAGs)

    Strongly Connected Components:
        Tarjan's Algorithm
        Kosaraju's Algorithm

... and many more, depending on the problem at hand.
Conclusion:

Understanding graphs and their algorithms is fundamental for any computer scientist or software engineer. They not only represent a wide variety of real-world problems but also provide efficient solutions to them. As you delve deeper into the realm of graphs, you'll discover their richness and the beauty of the problems they represent.
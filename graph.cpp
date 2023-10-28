//Graph representation

//Space complexity: O|(V| + |E|) where |V| is the number of vertices and |E| is the number of edges

#include <iostream>

using namespace std;

class Edge
{
    int startVertex;
    int endVertex;
    int weight; // if it is a weighted graph
};

string vertex_list[MAX_SIZE]; //array of strings to store the vertices
Edge edge_list[MAX_SIZE]; //array of edges to store the edges
#pragma once
#include <vector>
using namespace std;

class Edge {
public:
    int n1, n2, w;  // node 1, node 2, weight
    Edge(int n1, int n2, int w) : n1(n1), n2(n2), w(w) {}
};

template <typename T>
class Graph {
public:
    vector<T> nodes;
    vector<Edge> edges;
};
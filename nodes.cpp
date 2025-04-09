//  g++ nodes.cpp -lSDL2 -lSDL2_image -lSDL2_ttf && ./a.out

#include "sdl_fw.hpp"

Framework fw("Graph");

class Edge { public:
    int n1, n2, w;  // node 1 node 2 and weight
    Edge(int n1, int n2, int w) :n1(n1), n2(n2), w(w) {}
};

class Graph { public:
    vector<V2> nodes;
    vector<Edge> edges;

    void addRandomNodes() {
        for (int i=0; i<100; i++) {
            nodes.push_back({rand()%500, rand()%400});
        }
    }

    void addEdge(V2 n1, V2 n2, int w) {
        int numberOfNodes = nodes.size();
        nodes.push_back(n1);
        nodes.push_back(n2);

        edges.push_back(Edge(numberOfNodes, numberOfNodes+1, 1));
    }

    void update(Mouse& mouse) {
        static int nSelectedNode = -1;
        if (mouse.leftPressed) {
            V2 mousePos = fw.mouse.pos;
            for(int i=0; i<nodes.size(); i++) {
                V2 p = nodes[i];
                if (distance_squared(mousePos, p) < 100)
                    nSelectedNode = i;
            }
        }
        if (!mouse.leftHeld) nSelectedNode = -1;

        if (nSelectedNode != -1)
            nodes[nSelectedNode] = mouse.pos;
    }

    void draw() {
        fw.set_draw_color(255,0,0);
        for(int i=0; i<nodes.size(); i++)
            fw.draw_circle(nodes[i], 10);
    }

};

    
int main() {
    Graph graph;
    //graph.addRandomNodes();
    graph.addEdge({100,100}, {200,200}, 1);
    while(true) {
        fw.blank();
        fw.update_input();

        graph.update(fw.mouse);
        graph.draw();
        fw.render();
    }
}
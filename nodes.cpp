//  g++ nodes.cpp -lSDL2 -lSDL2_image -lSDL2_ttf && ./a.out

#include "sdl_fw.hpp"

Framework fw("Graph");

class Graph { public:
    vector<V2> nodes;

    void addRandomNodes() {
        for (int i=0; i<100; i++) {
            nodes.push_back({rand()%500, rand()%400});
        }
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

    while(true) {
        fw.blank();
        fw.update_input();

        graph.update(fw.mouse);
        graph.draw();
        fw.render();
    }
}
//  g++ main.cpp -lSDL2 -lSDL2_image -lSDL2_ttf && ./a.out

#include "sdl_fw.hpp"

Framework fw("Reflecting a ray of a edge");

class Edge { public:
    Edge(int x1, int y1, int x2, int y2) :p1(x1,y1), p2(x2,y2) {}
    Edge(V2 p1, V2 p2) :p1(p1), p2(p2) {}

    V2 p1, p2;

    void draw() {
        fw.set_draw_color(255,0,0);
        fw.draw_circle(p1, 10);
        fw.draw_circle(p2, 10);

        fw.draw_line(p1, p2);
    }

    void print_angle() {
        cout << tan((p2.y-p1.y) / (p2.x - p1.x)) / M_PI << "Pi";
    }
};

int main() {
    Edge edge(100,100, 200,200);
    cout << edge.p1 << "\t" << edge.p2;
    while(true) {
        fw.blank();
        fw.update_input();
        edge.draw();
        fw.render();
        edge.print_angle();
        cout << "\n" << flush;
    }
}
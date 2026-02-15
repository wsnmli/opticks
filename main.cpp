//  g++ main.cpp -lSDL2 -lSDL2_image -lSDL2_ttf && ./a.out

#include "sdl_fw.hpp"

Framework fw("Reflecting a ray of a union of planar circuits");

class Edge { public:
    int n1, n2, w;  // node 1 node 2 and weight
    Edge(int n1, int n2, int w) :n1(n1), n2(n2), w(w) {}
};

template <typename T>
class Graph { public: 
    vector<T> nodes;
    vector<Edge> edges;
};

class PlanarGraph : public Graph<V2> { public:

    void addRandomNodes() {
        for (int i=0; i<100; i++) {
            nodes.push_back({rand()%500, rand()%400});
        }
    }

    double angleOfEdge(int n) {
        //  find the angle of the nth edge with respect to the x-axis

        //  find the edge
        const Edge edge = edges[n];
        //  find the value of p1 and p2
        V2 p1 = nodes[edge.n1];
        V2 p2 = nodes[edge.n2];

        if (p1.x == p2.x) return M_PI/2;
        if (p1.y == p2.y) return 0;

        if (p2.x < p1.x && p2.y < p1.y) swap(p1, p2);
        else if (p2.x > p1.x && p2.y < p1.y) swap(p1, p2);

        if (p2.x > p1.x && p2.y > p1.y) return atan((p2.y-p1.y)/double(p2.x-p1.x));
        else return (M_PI /2) - atan((p2.x-p1.x) / double(p2.y-p1.y));
    }

    void addEdge(V2 n1, V2 n2, int w) {
        int numberOfNodes = nodes.size();
        nodes.push_back(n1);
        nodes.push_back(n2);

        edges.push_back(Edge(numberOfNodes, numberOfNodes+1, 1));
    }

    void addSquare(V2 p, int s) {
        //  where p is the postion and s is its size.
        //  points for model square
        V2 p1(-1,-1), p2(1,-1), p3(1,1), p4(-1,1);
        
        //  then resize the points
        p1 *= s;
        p2 *= s;
        p3 *= s;
        p4 *= s;

        p1 += p;
        p2 += p;
        p3 += p;
        p4 += p;
        
        int numberOfNodes = nodes.size();
        nodes.push_back(p1);
        nodes.push_back(p2);
        nodes.push_back(p3);
        nodes.push_back(p4);
        for (int i=numberOfNodes; i<numberOfNodes+3; i++) {
            edges.push_back(Edge(i, i+1, 1));
        } edges.push_back(Edge(numberOfNodes, numberOfNodes+3, 1));
    }

    void update(const Mouse& mouse) {
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

    void draw() const {   //  draw the graph
        //  draw edges
        for (int i=0; i<edges.size(); i++) {
            const Edge edge = edges[i];
            const V2 p1 = nodes[edge.n1];
            const V2 p2 = nodes[edge.n2];
            if (edge.w == 1) {
                fw.set_draw_color(255,255,255);
                fw.draw_line(p1, p2);
            }
        }

        //  draw nodes
        fw.set_draw_color(255,0,0);
        for(int i=0; i<nodes.size(); i++)
            fw.draw_circle(nodes[i], 10);

    }

};

class Raycaster { public:
    //  model points
    const V2 m1{14,0}, m2{-7, 10}, m3{-7, -10};
    V2 ce;   // centre of traingle
    
    V2 p1, p2, p3;
    double x = 0;

    Raycaster(const V2& c) :ce(c) {}

    void draw() { // draw the triangle that the rays emmit from
        //  rotate the points
        p1.x = (m1.x*cos(x)) - (m1.y*sin(x));
        p2.x = (m2.x*cos(x)) - (m2.y*sin(x));
        p3.x = (m3.x*cos(x)) - (m3.y*sin(x));

        p1.y = (m1.x*sin(x)) + (m1.y*cos(x));
        p2.y = (m2.x*sin(x)) + (m2.y*cos(x));
        p3.y = (m3.x*sin(x)) + (m3.y*cos(x));
        
        //  then translate the points
        p1 += ce;
        p2 += ce;
        p3 += ce;

        fw.set_draw_color(0,0,255);
        fw.draw_line(p1,p2);
        fw.draw_line(p2,p3);
        fw.draw_line(p3,p1);
    }

    void castRays(const PlanarGraph& g) const {
        // draw intital ray
        V2 start = ce;
        int dx = 1200*cos(x);
        int dy = 1200*sin(x);

        V2 end = start + V2(dx, dy);


        //  find the equation of the raycaster line in the form: ly + mx + n = 0
        double l1, m1, n1;
        eqOfline2(l1, m1, n1, start, end);
        //  go through every edge in the graph
        //  check if the ray intersects with the edge
        //  find the index of the closest of edge

        int edgeIndex = -1;
        int closestDist2 = 1e9;
        V2 cloestP;
        for (int i=0; i<g.edges.size(); i++) {
            //  find the equation of the line for each edge
            const V2 e1 = g.nodes[g.edges[i].n1]; 
            const V2 e2 = g.nodes[g.edges[i].n2];
            double l2, m2, n2;
            eqOfline2(l2, m2, n2, e1, e2);

            V2 p;  // the point of intersection
            
            //  check to see if the lines are parallel
            if (fabs((m1*l2) - (m2*l1)) < 0.00001) continue;
            p = pointOfIntersection2(l1,m1,n1,l2,m2,n2);
            
            //  check to see if the point intersects the edge
            if (p.x < min(e1.x, e2.x)) continue;
            if (p.x > max(e1.x, e2.x)) continue;
            if (p.y < min(e1.y, e2.y)) continue;
            if (p.y > max(e1.y, e2.y)) continue;

            V2f dir = {cosf(x), sinf(x)}; // the rays direction
            V2 toPoint = { p.x - ce.x, p.y - ce.y };
                if (dir.x * toPoint.x + dir.y * toPoint.y < 0)
                    continue;  // point is behind the ray

            //  if the code has gotten this far then the ray intersects an edge
            int dist2 = distance_squared(ce, p);
            if (dist2 < closestDist2) {
                closestDist2 = dist2;
                cloestP = p;
                edgeIndex = i;
            }
            
        }
        fw.set_draw_color(255,255,255);
        if (edgeIndex == -1) // no edge was hit
            fw.draw_line(start, end);
        else
            fw.draw_line(start, cloestP);
             
    }

    void update(const Keyboard& keyboard) {
        if (keyboard.aHeld) ce -= {10, 0};
        if (keyboard.dHeld) ce += {10, 0};
        if (keyboard.wHeld) ce -= {0, 10};
        if (keyboard.sHeld) ce += {0, 10};

        if (keyboard.leftHeld) x -= 0.07;
        if (keyboard.rightHeld) x += 0.07;
        if (x < 0) x += 2*M_PI;
        if (x >= 2*M_PI) x -= 2*M_PI;
    }
};
//  space apps challenge

int main() {
    PlanarGraph graph;
    graph.addSquare({W_WIDTH/2, W_HEIGHT/2}, 100);
    graph.addSquare({W_WIDTH/2-80, W_HEIGHT/2-200}, 50);

    Raycaster raycaster({W_WIDTH/2, W_HEIGHT/2});
    
    while(true) {
        fw.blank();
        
        graph.update(fw.mouse);
        graph.draw();

        raycaster.update(fw.keys);
        raycaster.draw();
        raycaster.castRays(graph);
        
        fw.update_input();
        fw.render();
    }
}
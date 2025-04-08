#pragma once

#include "vector2i.hpp"
#include "matrix_t.hpp"
#include "vector_functions.hpp"
#include "../sdl_fw.hpp"

#include <vector>
#include <algorithm>
using namespace std;


class Labeled_graph { public:
	vector<Vector2i> nodes;
	Matrix<int> edges = Matrix<int>(1,1);
public:
	void add_node(const Vector2i &v) {
		if (size() == 0)
			nodes.push_back(v);
	//	check to see if v is not in nodes.
		else if (!in(v, nodes)) {
			nodes.push_back(v);
			edges.resize(size(), size());
		} else cerr << v << " is already in nodes\n";
	}

	void remove_node(Vector2i v) {
		if (!in(v, nodes)) cerr << v << " not in nodes\n";
		else {
		//	find postion of v in nodes
		int p = find_index(v, nodes);
			edges.delete_row(p);
			edges.delete_col(p);

			nodes.erase(nodes.begin() + p);
		}
	}

	void remove_node(int i) { remove_node(nodes[i]); }

	void print_nodes() {
		for (auto i : nodes) cout << i;
	}

	void add_edge(Vector2i v1, Vector2i v2) {
	//	check to see if both elemenets are in nodes
		if (in(v1, nodes) && in(v2, nodes)) {
	//	find the postions p1, p2 of both elemenets
		int p1 = find_index(v1, nodes);
		int p2 = find_index(v2, nodes);
		edges(p1, p2) += 1;
		edges(p2, p1) += 1;
		} else cerr << "One of the elements is not in the graph\n";
	}

	void add_edge(int a, int b) {
	//	add an edge between the element in the ath and bth postion
		if (max(a, b) > size())
			cerr << "index larger than the size of G\n";
		else {
			edges(a,b) +=1; edges(b,a) += 1; }
	}

	int size() { return nodes.size(); }

	vector<Vector2i> neighbours(Vector2i e) {
		vector<Vector2i> tmp;
		if (!in(e, nodes)) { cerr << e << " not in G\n"; return tmp;}
		else {
			// find the index of e in nodes
			int p = find_index(e, nodes);
			for (int k=0; k<size(); k++) 
				if (edges(p, k) !=0)
					tmp.push_back(nodes[k]);
			return tmp;
		}
	}

	bool is_connected(Vector2i a, Vector2i b) {
		if (!in(a, nodes)) { cerr << a << " is not in nodes\n"; return false; }
		else if (!in(b, nodes)) { cerr << b << "is not in nodes\n"; return false; }
		else {
			vector<Vector2i> Neighbours = neighbours(a);	//	captilization to stop my head hurting from name confustion
			vector<Vector2i> visited;
		}
	}

	int degree(Vector2i a) {
		if (!in(a, nodes)) { cerr << a << " is not in nodes\n"; return 0; }
		else return neighbours(a).size();
	}

	void stretch(float t) {
		for (int i=0; i<size(); i++) {
			nodes[i].x *= t;
			nodes[i].y *= t;
		}
	}

	void shift(Vector2i v) {
		for (int i=0; i<size(); i++) {
			nodes[i].x += v.x;
			nodes[i].y += v.y;
		}
	}
	/*		commented out coz I couldnt work out how to use extern propaly
	void draw() {
		fw.set_draw_color(255,0,0);
		for (auto i : nodes) fw.draw_circle(i, 5);
		for (int i=0; i < size(); i++)
			for (int j=0; j<size(); j++)
				if (edges(i,j) != 0)
					fw.draw_line(nodes[i], nodes[j]);
	}
	*/

};

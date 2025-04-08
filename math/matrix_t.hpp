#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
class Matrix {
	int rows, cols;
	vector<vector<T>> data;

public:
	Matrix(int r, int c) :rows(r), cols(c) {
		data.resize(rows);
		for (int i = 0; i<rows; i++)
			data[i].resize(cols);
	}

	T& operator()(int r, int c) { return data[r][c]; }

	const T& operator()(int r, int c) const { return data[r][c]; }

	void resize(int r, int c) {
		Matrix<T> tmp(r,c);
		for(int i=0; i<min(r, this->rows); i++)
			for(int j=0; j<min(c, this->cols); j++)
				tmp(i,j) = (*this)(i,j);
		*this = tmp;
	}

	void delete_row(int r) {
		rows--;
		data.erase(data.begin() + r);
	}

	void delete_col(int c) {
		cols--;
		for (int i=0; i<rows; i++) {
			data[i].erase(data[i].begin() + c);
		}
	}

	friend ostream& operator<<(ostream& os, const Matrix<T> &M) {
		for(int i=0; i<M.rows; i++) {
			for(int j=0; j<M.cols; j++) {
				os << M(i,j) << ' ';
			} os << endl;
		} return os;
	}
};

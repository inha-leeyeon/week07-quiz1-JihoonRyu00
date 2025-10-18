#include <iostream>
#include <string>
#include <vector>
#include "Point.h"
#include "Square.h"

// Point
Point::Point(int px, int py) {
	x = px;
	y = py;
}
int Point::getX() const { return x; }
int Point::getY() const { return y; }
void Point::setX(int px) { x = px; }
void Point::setY(int py) { y = py; }

// Square
Square::Square(const string name, int px, int py, unsigned int side) :Point(px, py) {
	this->name = name;
	this->side = side;
	area = side * side;
}
unsigned int Square::getSide() const { return side; }
unsigned int Square::getArea() const { return area; }
string Square::getName() const { return name; }
void Square::setSide(unsigned int side) {
	this->side = side;
	setArea(side * side);
}
void Square::setArea(unsigned int area){
	this->area = area;
}
void Square::setName(string name) { this->name = name; }

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<Square> squares;
	for (int i = 0;i < N;i++) {
		string name;
		int px, py, side;
		cin >> name >> px >> py >> side;
		squares.push_back(Square(name, px, py, side));
	}

	cout << endl;
	vector<Square> sortedByArea = squares;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			if (sortedByArea[j].getArea() > sortedByArea[j + 1].getArea()) {
				Square temp = sortedByArea[j];
				sortedByArea[j] = sortedByArea[j + 1];
				sortedByArea[j + 1] = temp;
			}
		}
	}
	cout << "Squares in increasing order of area" << endl;
	for (const auto& s : sortedByArea) {
		cout << s.getName() << "(" << s.getX() << ", " << s.getY() << ") "
			<< "side=" << s.getSide() << ", area=" << s.getArea() << endl;
	}

	cout << endl;
	vector<Square> sortedByMaxX = squares;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			int max_x_j = sortedByMaxX[j].getX() + sortedByMaxX[j].getSide();
			int max_x_j_plus_1 = sortedByMaxX[j + 1].getX() + sortedByMaxX[j + 1].getSide();

			if (max_x_j > max_x_j_plus_1) {
				Square temp = sortedByMaxX[j];
				sortedByMaxX[j] = sortedByMaxX[j + 1];
				sortedByMaxX[j + 1] = temp;
			}
		}
	}
	cout << "Squares in increasing order of max x-coordinate" << endl;
	for (const auto& s : sortedByMaxX) {
		cout << s.getName() << "(" << (s.getX() + s.getSide()) << ", " << s.getY() << ") "
			<< "side=" << s.getSide() << ", area=" << s.getArea() << endl;
	}

	cout << endl;
	vector<Square> sortedByMaxY = squares;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - 1 - i; j++) {
			int max_y_j = sortedByMaxY[j].getY() + sortedByMaxY[j].getSide();
			int max_y_j_plus_1 = sortedByMaxY[j + 1].getY() + sortedByMaxY[j + 1].getSide();

			if (max_y_j > max_y_j_plus_1) {
				Square temp = sortedByMaxY[j];
				sortedByMaxY[j] = sortedByMaxY[j + 1];
				sortedByMaxY[j + 1] = temp;
			}
		}
	}
	cout << "Squares in increasing order of max y-coordinate" << endl;
	for (const auto& s : sortedByMaxY) {
		cout << s.getName() << "(" << s.getX() << ", " << (s.getY() + s.getSide()) << ") "
			<< "side=" << s.getSide() << ", area=" << s.getArea() << endl;
	}
}
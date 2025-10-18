#pragma once

#include <iostream>
#include <fstream>

using namespace std;

class point {
private:
	int x, y;

public:

	point(int x, int y);

	point();

	friend ostream& operator<<(ostream& os, const point& examp);

	void set_x(int d);
	void set_y(int d);

	int get_x() const;
	int get_y() const;

};
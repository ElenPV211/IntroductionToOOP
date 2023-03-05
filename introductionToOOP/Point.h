#pragma once
#include<iostream>
using namespace std;

//////////////////////////////////////////////////////////////////
//////------CLASS DECLARATION------//////////////////////////////
class Point;
Point operator+(const Point& left, const Point& right);

class Point
{
	double x;
	double y;
public:
	double get_x() const;
	double get_y() const;
	void set_x(double x);
	void set_y(double y);

	//----------Constructors:------------------------

	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();

	//-------------Operators:-------------//

	Point& operator = (const Point& other);
	double distance(const Point& other)const;

	//----------Metods:------------------
	void print()const;

};
////////////----END CLASS DECLARATION---/////////////
/////////////////////////////////////////////////////


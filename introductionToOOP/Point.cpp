#include"Point.h"

////////////////////////////////////////////////////////
/////////------ÎÏÐÅÄÅËÅÍÈÅ ÊËÀÑÑÀ - CLASS DEFINITION ///

double Point::get_x() const
{
	return x;
}
double Point::get_y() const
{
	return y;
}
void Point::set_x(double x) //îáû÷íî set íè÷åãî íå âîçâðàùàþò ïîýòîìó void
{
	this->x = x;
}
void Point::set_y(double y)
{
	this->y = y;
}

//----------Constructors:------------------------

Point::Point(double x, double y) :x(x), y(y)
{
	cout << "Constructor:\t\t" << this << endl;
}

Point::Point(const Point& other) :x(other.x), y(other.y)
{
	cout << "CopyConstructor:\t" << this << endl;
}

Point::~Point()
{
	cout << "Destructor:\t" << this << endl;
}

//-------------Operators:-------------//

Point& Point::operator = (const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
double Point::distance(const Point& other)const//const äåëàåò this íåäîñòóïíûì äëÿ èçìåíåíèÿ
{
	double x_distance = this->x - other.x;
	double y_distance = this->y - other.y;
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}

///////----------Metods:------------------//////////

void Point::print()const
{
	cout << "X = " << x << "\tY = " << y << endl;
}

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	return res;
}

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
/////////////---ÊÎÍÅÖ ÎÏÐÅÄÅËÅÍÈß ÊËÀÑÑÀ - CLASS DEFINITION END-/////
/////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

class Fraction
{
	int z;
	int g;

public:
	int get_z() const
	{
		return z;
	}
	int get_g() const
	{
		return g;
	}
	void set_z(int z)
	{
		this->z = z;
	}
	void set_y(int g)
	{
		this->g = g;
	}
	//Constructors:
	Fraction(int z=0,int g=0)
	{
		this->z = z;
		this->g = g;
		cout << "Constructor:\t" << this << endl;
	}
	/*Fraction(const Fraction& other)
	{
		this->x = x;
		this->y = y;
		cout << "CopyConstructor:\t" << this << endl;
	}*/
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	
	//Metods:
	void s()const
	{
		cout << "Z = " << z << "\tG = " << g << endl;
	}

};

//int fraction(Fraction& A, Fraction& B)
//{  }

int main()
{
	double C = 0;
	setlocale(0, "");
	Fraction A = {4,5};
	A.s();

}
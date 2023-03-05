#include "Fraction.h"

///////////////////////////////////////////////////////////////
/////////////����������� ������ - CLASS DEFINITION  ///////////

int Fraction::get_integer()
{
	return integer;
}
int Fraction::get_numerator()const
{
	return numerator;
}
int Fraction::get_denominator()const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}

///////----------Constractors:---------------//////

Fraction::Fraction() :integer(), numerator(), denominator()
{
	//this->integer = 0;
	//this->numerator = 0;
	//this->denominator = 1;
	cout << "DefaultConstructor:\t" << this << endl;

}

Fraction::Fraction(int integer) :integer(integer), numerator(0), denominator(1)
{
	//this->integer = integer;
	//this->numerator = 0;
	//this->denominator = 1;
	cout << "1ArgConstructor: \t" << this << endl;

}
Fraction::Fraction(double decimal)
{
	decimal += 1e-10;
	integer = decimal; //��������� ����� ����� ���������� �����
	decimal -= integer;//������� ����� ����� ������������ �����
	denominator = 1e+9; //���������� ����������� ��������� �����������
	numerator = decimal * denominator; //��� ������� ����� ���������� ����� ��������� � ���������
	reduce();
	cout << "1ArgConstructor:\t" << this << endl;
}

Fraction::Fraction(int numerator, int denominator) :integer(0), numerator(numerator)
{
	//this->integer = 0;
	//this->numerator = numerator;
	set_denominator(denominator);

	cout << "Constructor:\t\t" << this << endl;
}

Fraction::Fraction(int integer, int numerator, int denominator) :integer(integer), numerator(numerator)
{
	//this->integer = integer;
	//this->numerator = numerator;
	set_denominator(denominator);
	cout << "Constructor:\t\t" << this << endl;
}
Fraction::Fraction(const Fraction& other) :integer(other.integer), numerator(other.numerator), denominator(other.denominator)
{
	//this->integer = other.integer;
	//this->numerator = other.numerator;
	//this->denominator = other.denominator;
	cout << "CopyConstructor:\t" << this << endl;
}
Fraction::~Fraction()
{
	cout << "Destructor:\t\t" << this << endl;
}
//----------------Operators--------------------------///

Fraction& Fraction::operator=(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& other)
{
	return *this = *this * other; // ��������� � ������� 
}
Fraction& Fraction::operator/=(const Fraction& other)
{
	return *this = *this / other;
}
Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{
	set_integer(integer);
	set_numerator(numerator);
	set_denominator(denominator);
	return *this;
}

//---------------Type-cast operators:-----------///

Fraction::operator int()  //������ ������� �������������� �� ���� � ���
{
	return integer;
}
Fraction::operator double()
{
	return (integer + (double)numerator / denominator);
}


/////--------------Metods:---------------///

Fraction& Fraction::reduce()   //���������� �����
{
	int more, less, rest;
	if (numerator > denominator)more = numerator, less = denominator;
	else more = denominator, less = numerator;
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more; //GCD - ���������� ����� ��������
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}

Fraction& Fraction::to_improper()//������� � ������������ �����
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
}

Fraction& Fraction::to_proper()// ������� � ���������� �����
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
}
Fraction Fraction::inverted()const //��������� ������������ ����� ��� ��������� ��� �������
{
	Fraction inverted = *this; //�������� ������
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}

void Fraction::print()const
{
	if (integer)cout << integer;
	if (numerator)
	{
		if (integer) cout << "(";
		cout << numerator << "/" << denominator;
		if (integer) cout << ")";
	}

	else if (integer == 0)cout << 0;
	cout << endl;
}

Fraction operator+(const Fraction& left, const Fraction& right)
{
	return Fraction
	(
		left + right,
		left.get_numerator() * right.get_denominator() + right.get_numerator() * left.get_denominator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator*(Fraction left, Fraction right)
//�������� �� ��������
{
	left.to_improper();
	right.to_improper();

	return Fraction // ��� ������ � ��� ���� ����� ������� ����� .to_proper
		//��������������� � ���������� �����
		(
			left.get_numerator() * right.get_numerator(),
			left.get_denominator() * right.get_denominator()
		).to_proper().reduce();
}

Fraction operator/(const Fraction& left, const Fraction& right) //��������� ������������� ������ �.�.
//��������� � ���� ������ ��� ������� �������������� �� ���� �� ���� �� �������������
{
	return left * right.inverted();//��������� ������ ����� ��������� �� ����������� �����
}
////////////////////////////////////////
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();//���������� � ������������� ����
	right.to_improper();

	return
		left.get_numerator() * right.get_denominator() ==
		right.get_numerator() * left.get_denominator();
}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return !(left == right);
	!true == false;
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	return left < right || left == right;
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left < right);
}
////////////////////////////////////////

istream& operator>>(istream& is, Fraction& obj)

{
	//�������� ���������� �� ������ (Extraction operator)

	const int SIZE = 256;
	char buffer[SIZE] = {};
	char delimiters[] = "/ ()";
	int number[3] = {};
	//is >> buffer;
	is.getline(buffer, SIZE);

	int n = 0; //������� ����� ����������� �� ������
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = atoi(pch);
	//for (int i = 0; i < n; i++)cout << number[i] << "\t"; cout << endl;
	obj = Fraction();  // �������� ������, ���������� ��� �� ������� �� ���������

	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2: obj.set_numerator(number[0]); obj.set_denominator(number[1]); break;
	case 3: obj(number[0], number[1], number[2]);
	}

	return is;
}

ostream& operator<<(ostream& os, Fraction& obj) //������ const �.�. integer �� ���������
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer()) os << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer()) cout << ")";
	}

	else if (obj.get_integer() == 0)cout << 0;
	cout << endl;
	return os;
}

/////////-����� ����������� ������ - CLASS DEFINITION END //////
///////////////////////////////////////////////////////////////

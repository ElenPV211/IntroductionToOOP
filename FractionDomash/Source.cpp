#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Fraction;

class Fraction
{
	int integer;//целая часть
	int numerator;//числитель
	int denominator;//знаменатель

public:

	int get_integer()	const
	{
		return integer;
	}
	int get_numerator()	const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}

	/////////// Constractors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;

	}

	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "1ArgConstructor: \t" << this << endl;

	}

	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);

		cout << "Constructor:\t\t" << this << endl;
	}

	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//   Operators

	Fraction& operator()(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		return *this;
	}

	//////////Metods:

	
	void print()const
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

};


////////////////////////////////////////
istream& operator>>(istream& is, Fraction& obj)

{
	//оператор извлечения из потока (Extraction operator)

	const int SIZE = 256;
	char buffer[SIZE] = {};
	char delimiters[] = "/ ()";
	int number[3] = {};
	
	is.getline(buffer, SIZE);

	int n = 0; //счетчик чисел извлеченных из строки
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		number[n++] = atoi(pch);
	
	obj = Fraction();  // Обнуляем объект, сбрасываем его до объекта по умолчанию

	switch (n)
	{
	case 1: obj.set_integer(number[0]); break;
	case 2: obj.set_numerator(number[0]); obj.set_denominator(number[1]); break;
	case 3: obj(number[0], number[1], number[2]);
	}

	return is;
}

ostream& operator<<(ostream& os, const Fraction& obj)
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

void main()
{
	setlocale(0, "");

	

	Fraction A(2, 3, 4);

	cout << "Введите простую дробь: ";
	cin >> A;
	cout << A << endl;

}
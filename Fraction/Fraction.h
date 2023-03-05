#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////
////////////-----���������� ������ - CLASS DECLARATION-----////


class Fraction;
Fraction operator*(Fraction left, Fraction right);// �������� ������� ��� ���������� �������
Fraction operator/(const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;//����� �����
	int numerator;//���������
	int denominator;//�����������

public:

	int get_integer();
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	///////----------Constractors:---------------//////

	Fraction();

	explicit Fraction(int integer);
	Fraction(double decimal);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();

	//----------------Operators--------------------------///

	Fraction& operator=(const Fraction& other);
	Fraction& operator*=(const Fraction& other);
	Fraction& operator/=(const Fraction& other);
	Fraction& operator()(int integer, int numerator, int denominator);

	//---------------Type-cast operators:-----------///

	explicit operator int();
	operator double();

	/////--------------Metods:---------------///

	Fraction& reduce();
	Fraction& to_improper();
	Fraction& to_proper();
	Fraction inverted()const;

	void print()const;
};

//////////����� ���������� ������ - CLASS DECLARATION END //////
///////////////////////////////////////////////////////////////

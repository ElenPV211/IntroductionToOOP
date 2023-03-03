#pragma once//��������� ������������ ������� �������, ��� ������ 
//����  ����� �������� � ������ ���� ��� �� �������� �� ���������� 
//includ-�� 
#include<iostream>
using namespace std;
/// ///////////////////////////////////////////////////////////////
/// ////////////////////���������� ������ - CLASS DECLARATION  //////

class String;
String operator+(const String& left, const String& right);//�������� ��������� +
ostream& operator<<(ostream& os, const String& obj);
class String
{
	int size;	//������ ������ � ������
	char* str;	//��������� �� ������ � ������������ ������
public:

	int get_size()const;//��������� �������
	const char* get_str()const;
	char* get_str();

	//---------------Constructors:-----------------
	explicit String(int size = 80);
	String(const char* str);
	//Deep copy (��������� �����������)
	String(const String& other);

	String(String&& other);
	~String();
	//---------------Operator:----------------------

	String& operator=(String&& other);
	String& operator+=(const String& other);
	String& operator=(const String& other);
	char operator[](int i) const;
	char& operator[](int i);

	//---------------Methods:------------------------
	void print()const;
};
/// ///////////////////����� ���������� ������ - CLASS DECLARATION END //////
/// ///////////////////////////////////////////////////////////////


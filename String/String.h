#pragma once//директива компоновщика которая говорит, что данный 
//файл  нужно включить в сборку один раз не зависимо от количества 
//includ-ов 
#include<iostream>
using namespace std;
/// ///////////////////////////////////////////////////////////////
/// ////////////////////ОБЪЯВЛЕНИЕ КЛАССА - CLASS DECLARATION  //////

class String;
String operator+(const String& left, const String& right);//прототип оператора +
ostream& operator<<(ostream& os, const String& obj);
class String
{
	int size;	//размер строки в Байтах
	char* str;	//указатель на строку в динамической памяти
public:

	int get_size()const;//заголовки методов
	const char* get_str()const;
	char* get_str();

	//---------------Constructors:-----------------
	explicit String(int size = 80);
	String(const char* str);
	//Deep copy (побитовое копирование)
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
/// ///////////////////КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА - CLASS DECLARATION END //////
/// ///////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;
/// ///////////////////////////////////////////////////////////////
/// ////////////////////ОБЪЯВЛЕНИЕ КЛАССА - CLASS DECLARATION  //////

class String;
String operator+(const String& left, const String& right);//прототип оператора +

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
/// ///////////////////////////////////////////////////////////////
/// ///////////////////КОНЕЦ ОБЪЯВЛЕНИЯ КЛАССА - CLASS DECLARATION END //////

///-----------------------------------------------------------

/// ///////////////////////////////////////////////////////////////
/// ////////////////////ОПРЕДЕЛЕНИЕ КЛАССА - CLASS DEFINITION  //////

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}
//----------------Constructors:-----------------------
String::String(int size) :size(size), str(new char[size] {})
{
	cout << "DefConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	for (int i = 0; str[i]; i++)this->str[i] = str[i];

	cout << "ConstructorChar:\t" << this << endl;

}//Deep copy (побитовое копирование)
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstructor:" << this << endl;
}

String::String(String&& other) :size(other.size), str(other.str)

{
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:" << this << endl;
}
String::~String()
{
	delete[] this->str;
	this->str = nullptr;
	cout << "Destructor:\t" << this << endl;
}
//---------------------Operator:-----------------------------

String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t" << this << endl;
	return *this;
}
String& String::operator=(const String& other)
{
	if (this == &other)return *this;// если наше значение = тому значению
	//то сразу выходим из оператора присваивания чтобы данные не обнулились
	delete[]this->str;

	this->size = other.size;
	//Deep copy (побитовое копирование)

	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{

	return *this = *this + other; // обращение к функции 
}

char String::operator[](int i) const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}

//-------------------Methods:-----------------------------
void String::print()const
{
	cout << "Size:\t" << size << endl;

	cout << "Str:\t" << str << endl;
}

String operator+(const String& left, const String& right)
{
	
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		cat[i + left.get_size() - 1] = right[i];
	return cat;

	// l-vaue = r-value;
}

ostream& operator<<(ostream& os, const String& obj)
{
	return (os << obj.get_str());
}

/// ///////////////////////////////////////////////////////////////
/// ////////////////////КОНЕЦ ОПРЕДЕЛЕНИЯ КЛАССА - CLASS DEFINITION END //////
#define HOME_WORK

void main()
{
	setlocale(LC_ALL, "");
	/*String str;
	str.print();*/

#ifdef HOME_WORK
	String str1 = "Hello";
	str1 = str1;
	cout << str1 << endl;

	//str1.print();

	String str2 = "World";
	cout << str2 << endl;

	//String str3 = str1 + str2; //Copy constractor
	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;


	String str4 = str1;
	cout << str4 << endl;

    #endif // HOME_WORK
}

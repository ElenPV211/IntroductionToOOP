#include"String.h"
///-----------------------------------------------------------

/// ///////////////////////////////////////////////////////////////
/// ////////////////////����������� ������ - CLASS DEFINITION  //////

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

}//Deep copy (��������� �����������)
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
	if (this == &other)return *this;// ���� ���� �������� = ���� ��������
	//�� ����� ������� �� ��������� ������������ ����� ������ �� ����������
	delete[]this->str;

	this->size = other.size;
	//Deep copy (��������� �����������)

	this->str = new char[size] {};
	for (int i = 0; i < size; i++)
		this->str[i] = other.str[i];
	cout << "CopyAssignment:\t" << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{

	return *this = *this + other; // ��������� � ������� 
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
/// ////////////////////����� ����������� ������ - CLASS DEFINITION END //////
#include<iostream>
using namespace std;

class String;
String operator+(const String& left, const String& right);

class String
{
	int size;	//размер строки в Байтах
	char* str;	//указатель на строку в динамической памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	//				Constructors:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str)+1;//+1для NULL - terminatora

		this->str = new char[size] {};

		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		
		cout << "ConstructorChar:\t" << this << endl;
	
	}
	String(const String& other)
	{
		this->size = other.size;
		//Deep copy (побитовое копирование)

		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}

	String(String&& other)

	{
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveConstructor:" << this << endl;

	}
	~String()
	{
		delete[] this->str;
		this->str = nullptr;
		cout << "Destructor:\t" << this << endl;
	}
	// Operator:

	String& operator=(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout <<"MoveAssignment:\t"<< this << endl;
		return *this;
	}

	String& operator+=(const String& other)
	{
		
			return *this = *this + other; // обращение к функции 
		}

	String& operator=(const String& other)
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
	char operator[](int i) const
	{
		return str[i];
	}
char& operator[](int i)
	{
		return str[i];
	}

	//				Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;

		cout << "Str:\t" << str << endl;
	}
};


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
	str3 = str1 + " " + str2;
	cout << str3 << endl;
	str1 += str2;
	cout << str1 << endl;


    #endif // HOME_WORK
}

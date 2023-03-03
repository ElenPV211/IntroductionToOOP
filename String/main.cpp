#include"String.h"

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

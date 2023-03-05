#include"Point.h"

//#define STRUCT_POINT //имя макроса
//#define CONSTRUCTOR_CHECK
//#define DISTANCE_CHECK
//#define ASSIGMENT_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT_POINT//создаём именованые блоки кода чтобы мы могли их сворачивать разворачивать
	int a;	//Объявление переменной 'a' типа 'int'
	Point A;//Объявление переменной 'A' типа 'Point'
	//Создание объекта 'A' структуры 'Point'
	//Создание экземпляра 'A' структуры 'Point'
	//Объекты классов и структур еще называют экземплярами классов и структур.

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;	//https://ru.wikipedia.org/wiki/%D0%92%D0%B5%D0%BD%D0%B3%D0%B5%D1%80%D1%81%D0%BA%D0%B0%D1%8F_%D0%BD%D0%BE%D1%82%D0%B0%D1%86%D0%B8%D1%8F
	cout << pA->x << "\t" << pA->y << endl;
#endif //STRUCT_POINT

#ifdef CONSTRUCTOR_CHECK
	Point A; //Здесь вызывается конструктор по умолчанию (Default
	//A.set_x(2);
	//A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();
	Point B = 5; //вызывается конструктор с одним параметром
	B.print();

	Point C(22, 33);
	C.print();
	Point D = C;
	D.print();

	Point E;
	E = D; //Copy assignment
	E.print();

#endif CONSTRUCTOR_CHECK
#ifdef DISTANCE_CHECK
	Point A(2, 3);
	A.print();
	Point B(4, 5);
	B.print();
	cout << delimiter << endl;
	cout << "Расстояние от точки А до точки В: " << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки В до точки А: " << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками А и В: " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками B и A: " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif //DISTANCE_CHECK

#ifdef ASSIGMENT_CHECK
	//Copy assigment:
	int a, b, c;
	a = b = c = 2;
	std::cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
#endif ASSIGMENT_CHECK
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3); A.print();
	Point B(4, 5); B.print();
	Point C = A + B; C.print();

	}




/*
--------------------------------------------------------------
.  - Оператор прямого доступа (Point operator)
	 используется для доступа к полям объекта по ИМЕНИ объекта.
-> - Оператор косвенного доступа (Arrow operator)
	 используется для доступа к полям объекта по АДРЕСУ объекта.
--------------------------------------------------------------
*/

/*
--------------------------------------------------------------
				OOP concepts:
1. Encapsulation - сокрытие определенной части класса от внешнего мира.
	Модификаторы доступа
		private:	закрытые поля, доступны только внутри класса
		public:		открытые поля, доступны из любого места программы
		protected:	защищенные поля, доступны только внутри класса, и его дочерних классов.
					используется только при наследовании.
	get/set-методы  используются для доступа к закрытым переменным в классе
		get (взять, получить) используются для доступа к закрытым переменным на чтение, т.е.,
							  позволяют получить значение закрытой переменной.
		set (задать, установить) используются для доступа к закрытым перемееным на запись, т.е.,
							  позволяют задать значение закрытой переменной.
							  Кроме того, set-методы обеспечивают фильтрацию данных.
2. Inheritance;
3. Polymorphism;
--------------------------------------------------------------
*/


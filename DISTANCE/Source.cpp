#include <iostream>
using namespace std;
#define tab "\t"

//			DEPRECATED:

//double x;
//double y;
//
//double a; // квадрат гипотенузы
//double b; // корень квадратный из квадрата гипотенузы, то есть расстояние до точки А из любой другой заданной точки.
//double c; // один из катетов условного треугольника
//double d; // второй из катетов условного треугольника
//			DEPRECATED:

class Point
{
	double x;
	double y;
public:
	double GetX()const
	{
		return x;
	}
	double GetY()const
	{
		return y;
	}
	void SetX(double x)
	{
		this->x = x;
	}
	void SetY(double y)
	{
		this->y = y;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
	~Point()
	{
	}
	void Print()const
	{
		cout << "X =" << tab << x << endl;
		cout << "Y =" << tab << y << endl;
	}
};
double distance(Point A, Point B)
{
	double c = A.GetX() - B.GetX();
	double d = A.GetY() - B.GetY();

	if (d < 0)
	{
		d = -d;
	}
	if (c < 0)
	{
		c = -c;
	}
	double a = pow(d, 2) + pow(c, 2);
	double b = sqrt(a);
	return b;
}

void main()
{
	setlocale(LC_ALL, "");

	cout << "Постоянные координаты точки А: " << endl;
	Point A(3, 5);
	A.Print();
	double x, y;
	cout << endl;
	cout << " Введите значение координаты х точки, от которой надо найти расстояние до точки А: ";	cin >> x;
	cout << endl;
	cout << " Введите значение координаты y точки, от которой надо найти расстояние до точки А: ";	cin >> y;

	Point B(x, y);
	//B.Print();
	cout << endl;
	cout << " Расстояние до точки А равно " << distance(A, B);
	cout << endl;
}

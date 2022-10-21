#include <iostream>
using namespace std;

double x;
double y;
double x1;
double s; // В данном случае "s" это замена логичного названия значения координаты "y1", но на "y1" студия жутко ругается...
double a; // квадрат гипотенузы
double b; // корень квадратный из квадрата гипотенузы, то есть расстояние между точками
double c; // один из катетов условного треугольника
double d; // один из катетов условного треугольника

double distance(double a, double d, double c, double b);

void main()
{
	setlocale(LC_ALL, "");

	cout << endl;
	cout << " Введите значение координаты х точки А: ";
	cin >> x;
	cout << endl;
	cout << " Введите значение координаты y точки А: ";
	cin >> y;
	cout << endl;
	cout << " Введите значение координаты х точки В: ";
	cin >> x1;
	cout << endl;
	cout << " Введите значение координаты y точки В: ";
	cin >> s;
	cout << endl;
	cout << " Расстояние между точками А и В будет равно " << distance(a, d, c, b);
	
}
double distance(double a, double d, double c, double b)
{
	d = x - x1;
	c = y - s;
	if (d < 0)
	{
		d = -d;
	}
	if (c < 0)
	{
		c = -c;
	}
	a = pow(d, 2) + pow(c, 2);
	b = sqrt(a);
	return b;
}
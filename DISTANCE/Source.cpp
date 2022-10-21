#include <iostream>
using namespace std; 
#define tab "\t"

double x;
double y; 

double a; // квадрат гипотенузы
double b; // корень квадратный из квадрата гипотенузы, то есть расстояние до точки А из любой другой заданной точки.
double c; // один из катетов условного треугольника
double d; // второй из катетов условного треугольника

	class Point
	{
	private:
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
		double distance(Point A, Point B)
		{
			c = A.x - B.x;
			d = A.y - B.y;
			
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
	};

	void main()
	{
		setlocale(LC_ALL, "");

		cout << "Постоянные координаты точки А: " << endl;
		Point A (3, 5);
		A.Print();

		cout << endl;
		cout << " Введите значение координаты х точки, от которой надо найти расстояние до точки А: ";
		cin >> x;
		cout << endl;
		cout << " Введите значение координаты y точки, от которой надо найти расстояние до точки А: ";
		cin >> y;

		Point B(x, y);
		//B.Print();
		cout << endl;
		cout << " Расстояние до точки А равно " << A.distance(A, B);
		cout << endl;
	}

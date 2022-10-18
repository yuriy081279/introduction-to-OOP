#include <iostream>
using namespace std;
//#define tab \t

class Point
{
private:

	double x;
	double y;

public:
	double GetX()
	{
		return x;
	}
	void SetX(double valueX)
	{
		x = valueX;
	}
	void SetY(double valueY)
	{
		y = valueY;
	}
	void Print()
	{
		cout << "X =" << "\t" << x << endl;
		cout << "Y =" << "\t" << y << endl;
	}


};
void main()
{
	setlocale(LC_ALL, "");
	//cout << "HELLO OOP" << endl;
	Point A;
	A.SetX(2.2);
	A.SetY(3.4);
	A.Print();

	/*double result = A.GetX();
	cout << result;*/

	/*cout << A. << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;*/
}
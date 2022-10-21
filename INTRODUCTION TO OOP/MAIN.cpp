#include <iostream>
using namespace std;
#define tab "\t"
//#define STRUCT_POINT 

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
	// methods
	Point()
	{
		x = y = double();
		//значение по умолчанию для дабл
		cout << "Constructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor;\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	
	void Print()const
	{
		cout << "X =" << tab << x << endl;
		cout << "Y =" << tab << y << endl;
	}
};

//#define GET_SET_CHECK 
void main()
{
	setlocale(LC_ALL, "");
	//cout << "HELLO OOP" << endl;
#ifdef STRUCT_POINT 
	Point A;
	A.SetX(2.2);
	A.SetY(3.4);
	A.Print();

	/*double result = A.GetX();
	cout << result;

	cout << A. << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;*/
#endif // STRUCT_POINT 

#ifdef GET_SET_CHECK
	Point A;
	A.SetX(2);
	A.SetY(3);
	A.Print();
	Point B;
	B.SetX(10);
	B.SetY(30);	
	B.Print();
#endif // GET_SET_CHECK
	Point A;
	A.Print();
	Point B = 5;
	B.Print(); 

	Point C(2, 3);
	C.Print();
}
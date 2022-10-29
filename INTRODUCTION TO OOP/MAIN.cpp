#include <iostream>
using namespace std;
#define tab "\t"


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
	//Point()
	//{
	//	x = y = double();
	//	//значение по умолчанию для дабл
	//	cout << "DefaultConstructor:\t" << this << endl;
	//}
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor;\t" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& h)
	{
		this->x = h.x;
		this->y = h.y;
		cout << "CopyConstructor: "<<this<<endl;
	}

	
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}
	Point& operator = (const Point& h)
	{
		this->x = h.x;
		this->y = h.y;
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}
	Point& operator++ ()
	{
			x++;
	        y++;
			return *this;
	}
	Point operator++(int)
	{
		Point xuy = *this;
		x++;
		y++;
		return xuy;
	}
	Point& operator()(double x, double y)
	{
		SetX(x);
		SetY(y);
		return *this;
	}
	void Print()const
	{
		cout << "X =" << tab << x << endl;
		cout << "Y =" << tab << y << endl;
	}
};

Point operator+(const Point& left, const Point& right)
{
	Point res;
	res.SetX(left.GetX() + right.GetX());
	res.SetY(left.GetY() + right.GetY());
	return res;
}
bool operator == (const Point& left, const Point& right)
{
	return left.GetX() == right.GetY() && left.GetY() == right.GetY();
	/*if (left.GetX() == right.GetY() && left.GetY() == right.GetY())
	{
		return true;
	}
	else
	{
		return false;
	}*/
}
bool operator != (const Point& left, const Point& right)
{
	return !(left == right);
	
}
bool operator<(const Point& left, const Point& right)
{
	return left.GetX() < left.GetX() && left.GetY() < right.GetY();
}
bool operator<=(const Point& left, const Point& right)
{
	return left.GetX() <= left.GetX() && left.GetY() <= right.GetY();
}
ostream& operator<<(ostream& oss, const Point& hmrzh)
{
	oss << "X= " << hmrzh.GetX();
	oss << "\tY= " << hmrzh.GetY();
	return oss;

}


//#define STRUCT_POINT 
//#define GET_SET_CHECK 
//#define ASSIGNMENT_OPERATOR_CHECK 
//#define ARITHMETICAL_OPERATORS_CHECK 
//#define COMPARISON_OPERATORS_CHECK 
void main()
{
	setlocale(LC_ALL, "");
	
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
#ifdef ASSIGNMENT_OPERATOR_CHECK

	Point A;
	A.Print();

	Point B = 5;
	B.Print();

	Point C(2, 3);
	C.Print();

	Point D = C;
	D.Print();

	Point E;
	E = C;
	E.Print();

	E = B = C = Point(2, 3);
#endif // 

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Point A(2, 3);
	Point B(4, 6);
	Point C = A + B;
	A.Print();
	B.Print();
	C.Print();
	++C;
	C.Print();
	C++;
	C.Print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	cout << (Point(2, 3) != Point(7, 8)) << endl;
	for (Point i = 0; i <= Point(10, 10); ++i)
	{
		i.Print();
	}
#endif // COMPARISON_OPERATORS_CHECK

	Point A;
	A(2, 3);
	A.Print();
	cout << A<<endl;
}
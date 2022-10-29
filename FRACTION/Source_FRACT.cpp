#include <iostream>
using namespace std;
#define tab "\t"
#define delim "--------------------------------------"
class Fraction;
Fraction operator*(Fraction left, Fraction right);

class Fraction
{
	int integer;  
	int numerator; 
	int denominator;

public:

	int Get_integer()const
	{
		return integer;
	}
	int Get_numerator()const
	{
		return numerator;
	}
	int Get_denominator()const
	{
		return denominator;
	}
	void Set_integer(int integer)
	{
		this->integer = integer;
	}
	void Set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void Set_denominator(int denominator)
	{
		if (denominator == 0)
		{
			denominator = 1;
		}
		this->denominator = denominator;
	}

	//constr
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
	}
	Fraction(int integer,int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		Set_denominator(denominator);
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		Set_denominator(denominator);
	}
	~Fraction()
	{

	}
	Fraction& to_improper()//перевод целой части в дробную
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()//перевод целой части в дробную
	{		
		integer = numerator/denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction& inverted()
	{
		Fraction inverted = *this;
			inverted.to_improper();
			/*int buffer = inverted.numerator;
			inverted.numerator = inverted.denominator;
				inverted.denominator = buffer;*/
			swap(inverted.numerator, inverted.denominator);
				return inverted;
	}
	Fraction& operator *=(const Fraction& other)
	{
		return *this = *this * other;
	}
	operator Fraction()const
	{
		//int = Fraction();
	}
};
Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.Set_numerator(left.Get_numerator() * right.Get_numerator());
	result.Set_denominator(left.Get_denominator() * right.Get_denominator());
	return result.to_proper();
}
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.Get_integer())os << obj.Get_integer();
	if (obj.Get_numerator())
	{
		if (obj.Get_integer())os << "(";
		os << obj.Get_numerator() << "/" << obj.Get_denominator();
		if (obj.Get_integer())os << ")";
	}
	else if (obj.Get_integer() == 0)os << 0;
	return os;
}

//ќѕ≈–ј“ќ–џ —–ј¬Ќ≈Ќ»я
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.Get_numerator() * right.Get_denominator()==
	       right.Get_numerator() * left.Get_denominator();
	        
}
bool operator!=(const Fraction left, const Fraction right)
{
	
	return!(left==right);

}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.Get_numerator()* right.Get_denominator() >
		right.Get_numerator() * left.Get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.Get_numerator() * right.Get_denominator() <
		right.Get_numerator() * left.Get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	
	return left > right || left == right;
}
bool operator<=(const Fraction& left, const Fraction& right)
{

	return !(left > right);
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction(
		left.Get_numerator() * right.Get_denominator(),
	right.Get_numerator()* left.Get_denominator()).to_proper();*/
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	Fraction res;	
	left.to_improper();
	right.to_improper();	
	res.Set_numerator(left.Get_numerator() * right.Get_denominator() + right.Get_numerator() * left.Get_denominator());
	res.Set_denominator(right.Get_denominator()* left.Get_denominator());
	return res.to_proper();
}
Fraction operator-(Fraction left, Fraction right)
{
	Fraction res;
	left.to_improper();
	right.to_improper();
	res.Set_numerator(left.Get_numerator() * right.Get_denominator() - right.Get_numerator() * left.Get_denominator());
	res.Set_denominator(right.Get_denominator() * left.Get_denominator());
	return res.to_proper();
}
//#define	CONSTRUCTORS_CHECK
//#define	ARITHMETICAL_OPERATORS_CHECK
//#define	COMPOUND_ASSIGNMENTS_CHECK
//#define	COMPARISON_OPERATORS_CHECK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A;
	cout << A << endl;
	Fraction B = 5;
	cout << B << endl;
	Fraction C(2, 3);
	cout << C << endl;
	Fraction D(2, 3, 4);
	cout << D << endl;
#endif // 
#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(1, 2, 4); 
	cout << A << endl;
	Fraction B(3, 3, 4);
	cout << B << endl;
	Fraction C = A + B;
	cout << C << endl;
	Fraction D = B - A;
	cout << D << endl;
	Fraction Z = A * B;
	cout << Z << endl;
#endif // ARITHMETICAL_OPERATORS_CHECK
#ifdef COMPOUND_ASSIGNMENTS_CHECK
	Fraction A(1, 2, 3);
	Fraction B(3, 4, 5);
	A *= B;
	cout << A << endl;
#endif // COMPOUND_ASSIGNMENTS_CHECK
	/*Fraction A(1, 2);
	Fraction B(5, 11);
	if (A == B)
	{
		cout << "дроби равны" << endl;
	}
	else
	{
		cout << "дроби не  равны" << endl;
	}*/
#ifdef COMPARISON_OPERATORS_CHECK
	cout << (Fraction(1, 2) <= Fraction(5, 9));
#endif // COMPARISON_OPERATORS_CHECK

	Fraction A = Fraction(5);
	cout << A << endl;
	cout << delim << endl;
	Fraction B;
	B = (Fraction)8;
	cout << delim << endl;
	cout << B;

	Fraction A(2, 3, 4);
		int a = A;

}
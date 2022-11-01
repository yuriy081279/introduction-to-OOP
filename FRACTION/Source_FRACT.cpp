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
		this;
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
	// Type cast operators
	explicit operator int()const
	{
		return integer+numerator/denominator;
	}
	explicit operator double()const
	{
		return integer + (double) numerator / denominator;
	}
	Fraction(double decimal)
	{
		integer = decimal;
		decimal = decimal + pow(10, -10);
		denominator = 1000000000;
		numerator = (decimal-integer)*denominator;
		reduce();
	}
	Fraction& reduce()
	{
		int more, less, ostatok;
		if (numerator > denominator)
		{
			more = numerator;
			less = denominator;
		}
		else
		{
			more = denominator;
			less = numerator;
		}
		do
		{
			ostatok = more % less;
			more = less;
			less = ostatok;
		} while (ostatok);
		int NOD = more;
		numerator = numerator / NOD;
		denominator = denominator / NOD;
		return *this;
	}
	/*Fraction& operator>>(const Fraction& obj)
	{
		int a, b, c;
		cout << "¬ведите целое число дроби ";
		cin >> a;
		obj.Get_integer();
		cout << endl;
		cout << "¬ведите числитель дроби ";
		cin >> b;
		obj.Get_numerator();
		cout << endl;
		cout << "¬ведите знаменатель число дроби ";
		cin >> c;
		obj.Get_denominator();
		cout << endl;
		return *this;
	}*/
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
istream& operator>>(istream& h,  Fraction& obj)
{	
	int a, b, c;
	cout << "¬ведите целое число дроби ";
	cin >> a;
	obj.Set_integer(a);
	cout << endl;
	cout << "¬ведите числитель дроби ";
	cin >> b;
	obj.Set_numerator(b);
	cout << endl;
	cout << "¬ведите знаменатель дроби ";
	cin >> c;
	obj.Set_denominator(c);
	cout << endl;	
	return h;
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
//#define	CONVERSION_FROM_OTHER_TO_CLASS
#define	VVOD_PROSTOY_DROBI_S_KLAVIATURY
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
	Fraction A = Fraction(5);
	cout << A << endl;
	cout << delim << endl;
	Fraction B;
	B = (Fraction)8;
	cout << delim << endl;
	cout << B;
#endif // COMPARISON_OPERATORS_CHECK
	
#ifdef CONVERSION_FROM_OTHER_TO_CLASS
	Fraction A(2, 3, 10);
	int a = (int)A;
	cout << a << endl;

	double b = (double)A;
	cout << b << endl;

	Fraction H = 2.8;
	cout << H << endl;

#endif // CONVERSION_FROM_OTHER_TO_CLASS
	
#ifdef VVOD_PROSTOY_DROBI_S_KLAVIATURY
	Fraction A;
	cout << "¬ведите простую дробь: ";
	cout << endl;
	cin >> A;
	cout << A;
#endif // VVOD

	
}
#include<iostream>
using namespace std;

class String
{
	size_t size;	//размер строки в Байтах
	char* str; // указатель на строку динамической памяти
public:
	const char* get_str()const
	{
		return str;
	}
	const size_t get_size()const
	{
		return size;
	}
	void set_size(size_t size)
	{
		this-> size = size;
	}
	void set_str(char* str)
	{
		this-> str = str;
	}

	explicit String(size_t size=80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefConstructor:\t"<<this<<endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Construcnor: \t" << endl;
	}	
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size]{};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
			
		}
		cout << "CopyConstructor: \t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor: \t"<<this<<endl;
	}
		//operators:

	String& operator=(const String& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[]this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
			
		}
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}	
	void Print()const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};
ostream& operator<<(ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String left, const String right)
{
	String res;
	res.set_size(left.get_size() + right.get_size());
	char* str = new char[res.get_size()];
	for (int i = 0; i < res.get_size(); i++)
	{
		if (i < left.get_size())
		{
			str[i] = left.get_str()[i];
			cout << str[i];
		}		
		if (i == left.get_size())
		{
			cout << " ";
		}				
	}
	for (int j = left.get_size(); j < res.get_size(); j++)
	{			
		str[j] = right.get_str()[j - left.get_size()];
		cout << str[j];			
	}
	cout << endl;		
	return res;
}
//#define CONSTRUCTORS_CHECK
#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	String str1;	//пустая строка размером 80 Байт
	str1.Print();
	cout << str1 << endl;

	String str2(23);
	str2.Print();

	String str3 = "Hello";
	str3.Print();

	String str4 = str3;
	cout << str4 << endl;

	String str5;
	str5 = str4;
	cout << str5 << endl;
#endif // CONSTRUCTORS_CHECK

	String str1 = "Hello";
	String str2 = "World";
	String str3 = str1 + str2;
	cout << str3 << endl;

	/*String str4 = "Пошло все в";
	String str5 = "Жопу!!";
	String str6 = str4 + str5;
	cout << str3 << endl;*/
}









#include <iostream>
using namespace std;

double x;
double y;
double x1;
double s; // � ������ ������ "s" ��� ������ ��������� �������� �������� ���������� "y1", �� �� "y1" ������ ����� ��������...
double a; // ������� ����������
double b; // ������ ���������� �� �������� ����������, �� ���� ���������� ����� �������
double c; // ���� �� ������� ��������� ������������
double d; // ���� �� ������� ��������� ������������

double distance(double a, double d, double c, double b);

void main()
{
	setlocale(LC_ALL, "");

	cout << endl;
	cout << " ������� �������� ���������� � ����� �: ";
	cin >> x;
	cout << endl;
	cout << " ������� �������� ���������� y ����� �: ";
	cin >> y;
	cout << endl;
	cout << " ������� �������� ���������� � ����� �: ";
	cin >> x1;
	cout << endl;
	cout << " ������� �������� ���������� y ����� �: ";
	cin >> s;
	cout << endl;
	cout << " ���������� ����� ������� � � � ����� ����� " << distance(a, d, c, b);
	
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
#include<iostream>
using namespace std;

#define delimiter "\n-------------------------------------------------\n"

void main()
{
	setlocale(LC_ALL, "");

	int a = 2;
	int& ra = a;
	ra += 3;
	cout << ra;
	cout << a << endl;
}
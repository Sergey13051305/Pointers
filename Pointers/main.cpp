#include <iostream>
using namespace std;

//#define pointer_baisics

void main()
{
	setlocale(LC_ALL, "");

#ifdef pointer_baisics
	int a = 2;
	int* pa = &a;
	cout << a << endl; // Вывод переменной 'а' на экран
	cout << &a << endl;// Взятие адреса переменной 'а' прямо при выводе.
	cout << pa << endl;// Вывод адреса переменной 'a', хранящегося в указателе 'pa'
	cout << *pa << endl;// разыменование указатиеля 'pa' и вывод на экран значяение по адресу  
#endif 
	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;

	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

	for (int* p_arr = arr; *p_arr!=0xCCCCCCCC; p_arr++)
	{
		cout << *p_arr << "\t";
	}
	cout << endl;
	
}
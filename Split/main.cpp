#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
setlocale(LC_ALL, "Rus");

const int n = 10;
int arr[n];
FillRand(arr, n);
Print(arr, n);

//1)Вычисляем размеры массивов:
int even_count=0;
int odd_count=0;
for (int i = 0; i < n; i++) arr[i] % 2 == 0 ? even_count++:odd_count++;
cout << endl;
//2) Выделяем память под массивы:
int* even_arr = new int[even_count];
int* odd_arr = new int[odd_count];
//3) Копируем значение в соответсвтующие массивы:
for (int i = 0,j=0, k=0; i < n; i++)arr[i] % 2 == 0 ? even_arr[j++] = arr[i]:odd_arr[k++] = arr[i];
cout << endl;
Print(even_arr, even_count);
Print(odd_arr, odd_count);
delete[] odd_arr;
delete[] even_arr;
cout << endl;
}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
	cout << endl;
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
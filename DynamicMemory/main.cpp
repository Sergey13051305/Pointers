#include <iostream>
using namespace std;

void FillRand(int arr[], int const n);
void Print(int arr[], int const n);

void main()
{
	setlocale(LC_ALL, "");

	int n = 5;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);
	delete[] arr;
}

void FillRand(int arr[], int const n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand()%100;
	}
}
void Print(int arr[], int const n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
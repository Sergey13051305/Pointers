#include <iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define DynamicMemory_1
//#define DynamicMemory_2

void FillRand(int arr[],  const int n);
void FillRand(int** arr,  const int rows, const int cols);

void Print(int arr[], int const n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, int value);
int* push_front(int* arr, int& n, int value);

int* insert(int* arr, int& n, int value, int index);

int* pop_back(int* arr, int& n);
int* pop_front(int* arr, int& n);

int* erase(int* arr, int& n, int value, int index);

void main()
{
	setlocale(LC_ALL, "");
#ifdef DynamicMemory_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добовляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добовляемое значение: "; cin >> value;
	arr = push_front(arr,n, value);
	Print(arr, n);

	int index;
	cout << "Введите индекс добовляемого элемента: "; cin >> index;
	cout << "Введите добовляемое значение: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	arr = erase(arr, n, value, index);
	Print(arr, n);

	delete[] arr;
#endif

#ifdef DynamicMemory_2
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;
	

	int** arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{ 
		arr[i] = new int[cols];
	}

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//1) Удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	//2)Удаляем массив указателей
	delete[] arr;

	for (int i = 0; i < cols; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
#endif
}

void FillRand(int arr[], int const n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand()%100;
	}
}

void FillRand (int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int* push_back(int* arr, int& n, int value)
{
	//1)Создаем буферный массив нужного размера(на 1 элемент больше)
	int* buffer = new int[n + 1];
	//2)Копируем все значения из исходного массива в буферрный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)Удаляем исходный массив:
	delete[] arr;
	//4)Подменяем адрес исходного массива, адресом нового массива:
	arr = buffer;
	buffer = nullptr; //NULL-pointer (указатель на 0)
	//cout << typeid(nullptr).name() << endl;
	//5)И только после этого в массив 'arr' можно добавить зеначение
	arr[n] = value;
	//6)После добавления элемента в массив количество его элементов увеличивается на 1
	n++;
	//7)Элемент добавлен
	return arr;
}

int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	buffer[0] = value;
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}

int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* pop_back(int* arr, int& n)
{
	//int* buffer = new int[n - 1];
	//for (int i = 0; i < i-n; i++)
	//{
	//	buffer[i] = arr[i];
	//}
	//delete[] arr;
	//arr = buffer;
	//n--;
	//return arr;
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
	//возврашает новый адресс массива
}

int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
	//в новый массив копируем все элементы кроме удаляемого
}
int* erase(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = ++index; i < n; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr;
	n--;
	return buffer;

}
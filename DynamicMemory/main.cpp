#include <iostream>
#include <ctime>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n----------------------------------------------------------------------\n"

//#define DynamicMemory_1
#define DynamicMemory_2
//#define PERFOMANCE_TEST

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);
 
void FillRand(int arr[],  const int n); 
void FillRand(int** arr,  const int rows, const int cols);

void Print(int arr[], int const n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int* arr, int& n, const int& value);
int** push_row_back(int** arr, int& rows, const int cols);
void push_col_back(int** arr, const int rows, int& cols);

int* push_front(int* arr, int& n, int value);
int** push_row_front(int** arr, int& rows, const int cols);
void push_col_front(int** arr, const int rows, int& cols);

int* insert(int* arr, int& n, int value, int index);
int** insert_row(int** arr, int& rows,const int cols,const int index);
void insert_col(int** arr, const int rows, int& cols, const int index);
 
int* pop_back(int* arr, int& n);
int** pop_row_back(int** arr, int& rows, const int cols);
void pop_col_back(int** arr, const int rows, int& cols);

int* pop_front(int* arr, int& n);
int** pop_row_front(int** arr, int& rows, const int cols);
void pop_col_front(int** arr, const int rows, int& cols);

int* erase(int* arr, int& n, int value, int index);
int** erase_row(int** arr, int& rows, const int cols, const int index);
void erase_col(int** arr,const int rows, int& cols, const int index);


void main()
{
	setlocale(LC_ALL, "");
	int index;
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
	cout << "Введите количество элементов строки: "; cin >> cols; cout << endl;
	cout << "Выводит двумерный динамический массив на экран: " << endl;

	
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
#ifdef PERFOMANCE_TEST
	cout << "Память выделена, для добавление строки нажмите любую клавишу" << endl;
	system("PAUSE");
	clock_t c_start = clock();
	arr = push_row_back(arr, rows, cols);
	clock_t c_end = clock();
	cout << "Строка добавлена: " << double(c_end - c_start) / CLOCKS_PER_SEC << endl;
	system("PAUSE");
#endif


	cout << delimiter << endl;
	cout << "добавляет пустую строку в конец двумерного динамического массива: " << endl;
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "добавляет пустую строку в начало двумерного динамического массива: " << endl;
	arr = push_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "вставляет пустую строку в двумерный динамический массив по заданному индексу: " << endl;
	cout << "Введите индекс добовляемого элемента: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);


	cout << delimiter << endl;
	cout << "удаляет последнюю строку двумерного динамического массива: " << endl;
	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "удаляет нулевую  строку двумерного динамического массива: " << endl;
	arr = pop_row_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "удаляет пустую строку в двумерном динамическом массиве по заданному индексу: " << endl;
	cout << "Введите индекс добовляемого элемента: "; cin >> index;
	arr = erase_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "добавляет пустой столбец в конец двумерного динамического массива: " << endl;
	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "добавляет пустой столбец в начало двумерного динамического массива: " << endl;
	push_col_front(arr, rows, cols);
	Print(arr, rows, cols);
	
	cout << delimiter << endl;
	cout << "вставляет пустой столбец в двумерный динамический массив по заданному индексу: " << endl;
	cout << "Введите индекс добовляемого элемента: "; cin >> index;
	insert_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "удаляет столбец с конца двумерного динамического массива" << endl;
	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "удаляет столбец с начала двумерного динамического массива" << endl;
	pop_col_front(arr, rows, cols);
	Print(arr, rows, cols);

	cout << delimiter << endl;
	cout << "удаляет столбец из двумерного динамического массива по заданному индексу: " << endl;
	cout << "Введите индекс добовляемого элемента: "; cin >> index;
	erase_col(arr, rows, cols, index);
	Print(arr, rows, cols);

	Clear(arr, cols);

#endif
}

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	return arr;
}
void Clear(int** arr, const int rows)
{
	//1) Удаляем строки
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

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

int* push_back(int* arr, int& n, const int& value)
{
	//1)Создаем буферный массив нужного размера(на 1 элемент больше)
	int* buffer = new int[n + 1];
	//2)Копируем все значения из исходного массива в буферрный:
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
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

int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) Создаем буферный массив указателей:
	int** buffer = new int* [rows + 1];
	//2) Копируем адреса строк из исходного массива в буфферный:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//3) Удаляем исходный массив указателей:
	delete[] arr;
	//4) Подменяем адрес массива указателей
	arr = buffer;
	//5) Создаем новую строку:
	arr[rows] = new int[cols] {};//Заполняет значение по умолчанию;
	//6) После добавлдения строки нужно увеличить количество строк с массива:
	rows++;
	//7)Возвращаем новый массив
	return arr;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаем буферную строку
		int* buffer = new int[cols + 1] {};
		//2) Копируем все содержимое из исходной строки в буферную:
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) Удаляем исходную строку
		delete[] arr[i];
		//4) Записываем адрес новой строки в массив указателей: 
		arr[i] = buffer;
	}
	cols++;
}

int* push_front(int* arr, int& n, int value)
{
	int* buffer = new int[n + 1];
	buffer[0] = value;
	for (int i = 0; i < n; i++)buffer[i+1] = arr[i];
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];
	buffer[0] = new int[cols] {};
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	rows++;
	return buffer;
}

void push_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++) 
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

int* insert(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
int** insert_row(int** arr, int& rows, const int cols, const int index)
{
	// Создаем новый массив с увеличенным числом строк на 1
	int** buffer = new int* [rows + 1];
	// Копируем строки из исходного массива до индекса в новый массив
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	// Вставляем новую строку в новый массив
	buffer[index] = new int[cols] {};
	// Копируем строки из исходного массива после индекса в новый массив со здвигом
	for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];
	// Удаляем исходный массив
	delete[] arr;
	// Увеличиваем число строк
	rows++;
	// Возвращаем новый массив
	return buffer;
}

void insert_col(int** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j+1] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}

int* erase(int* arr, int& n, int value, int index)
{
	int* buffer = new int[n - 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = ++index; i < n; i++)buffer[i-1] = arr[i]; 
	delete[] arr;
	n--;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int*[rows - 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index+1; i < rows; i++)buffer[i - 1] = arr[i];
	delete[] arr;
	rows--;
	return buffer;
}

void erase_col(int** arr, const int rows, int& cols, const int index) 
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index + 1; j < cols; j++)buffer[j - 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
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

int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

void pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
	int* buffer = new int[cols - 1];
		for (int j = 0; j < cols-1; j++)buffer[j] = arr[i][j];
		delete arr[i];
		arr[i] = buffer;
	}
	cols--;
}

int* pop_front(int* arr, int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i+1];
	delete[] arr;
	return buffer;
	//в новый массив копируем все элементы кроме удаляемого
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
void pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j+1];
		delete arr[i];
		arr[i] = buffer;
	}
	cols--;
}


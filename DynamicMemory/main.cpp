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
template <typename T>
T** Allocate(const int rows, const int cols);

template <typename T>
void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n);
void FillRand(double arr[], const int n);
void FillRand(char arr[], const int n);

void FillRand(int** arr, const int rows, const int cols);
void FillRand(char** arr, const int rows, const int cols);

template <typename T>void Print(T arr[], int const n);
template <typename T>void Print(T** arr, const int rows, const int cols);

template <typename T>
T* push_back(T* arr, int& n, const T& value);
template <typename T>
T** push_row_back(T** arr, int& rows, const int cols);
template <typename T>
void push_col_back(T** arr, const int rows, int& cols);

template <typename T>
T* push_front(T* arr, int& n, T value); 
template <typename T>
T** push_row_front(T** arr, int& rows, const int cols);
template <typename T>
void push_col_front(T** arr, const int rows, int& cols);

template <typename T>
T* insert(T* arr, int& n, T value, int index);

template<typename T>
T** insert_row(T** arr, int& rows, const int cols, const int index);
template<typename T>
void insert_col(T** arr, const int rows, int& cols, const int index);

template <typename T>
T* pop_back(T* arr, int& n);
template <typename T>
T** pop_row_back(T** arr, int& rows, const int cols);
template <typename T>
void pop_col_back(T** arr, const int rows, int& cols);

template <typename T>
T* pop_front(T* arr, int& n);
template <typename T>
T** pop_row_front(T** arr, int& rows, const int cols);
template <typename T>
void pop_col_front(T** arr, const int rows, int& cols);

template <typename T>
T* erase(T* arr, int& n, int value, int index);
template <typename T>
T** erase_row(T** arr, int& rows, const int cols, const int index);
template <typename T>
void erase_col(T** arr, const int rows, int& cols, const int index);

	typedef char DataType;

void main()
{
	setlocale(LC_ALL, "");
#ifdef DynamicMemory_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	DataType* arr = new DataType[n];
	FillRand(arr, n);
	Print(arr, n);

	DataType value;
	cout << "Введите добовляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добовляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
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
	int index;
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols; cout << endl;
	cout << "Выводит двумерный динамический массив на экран: " << endl;

	DataType** arr = Allocate<DataType>(rows, cols);
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
template <typename T>
T** Allocate(const int rows, const int cols)
{
	T** arr = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols];
	}
	return arr;
}

template <typename T>
void Clear(T** arr, const int rows)
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
		*(arr + i) = rand() % 100;
	}
}
void FillRand(double arr[], int const n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 10000;
		arr[i] /= 100;
	}
}

void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand();
	}
}
void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(char** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}
template <typename T>void Print(T arr[], int const n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}

template <typename T>void Print(T** arr, const int rows, const int cols)
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

template <typename T>
T* push_back(T* arr, int& n, const T& value)
{
	//1)Создаем буферный массив нужного размера(на 1 элемент больше)
	T* buffer = new T[n + 1];
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
template <typename T>
T** push_row_back(T** arr, int& rows, const int cols)
{
	//1) Создаем буферный массив указателей:
	T** buffer = new T* [rows + 1];
	//2) Копируем адреса строк из исходного массива в буфферный:
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	//3) Удаляем исходный массив указателей:
	delete[] arr;
	//4) Подменяем адрес массива указателей
	arr = buffer;
	//5) Создаем новую строку:
	arr[rows] = new T[cols] {};//Заполняет значение по умолчанию;
	//6) После добавлдения строки нужно увеличить количество строк с массива:
	rows++;
	//7)Возвращаем новый массив
	return arr;
}

template <typename T>
void push_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаем буферную строку
		T* buffer = new T[cols + 1] {};
		//2) Копируем все содержимое из исходной строки в буферную:
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) Удаляем исходную строку
		delete[] arr[i];
		//4) Записываем адрес новой строки в массив указателей: 
		arr[i] = buffer;
	}
	cols++;
}
template <typename T>
T* push_front(T* arr, int& n, T value)
{
	T* buffer = new T[n + 1];
	buffer[0] = value;
	for (int i = 0; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}
template <typename T>
T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];
	buffer[0] = new T[cols] {};
	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	rows++;
	return buffer;
}
template <typename T>
void push_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j + 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template <typename T>
T* insert(T* arr, int& n, T value, int index)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}
template <typename T>
T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	// Создаем новый массив с увеличенным числом строк на 1
	T** buffer = new T* [rows + 1];
	// Копируем строки из исходного массива до индекса в новый массив
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	// Вставляем новую строку в новый массив
	buffer[index] = new T[cols] {};
	// Копируем строки из исходного массива после индекса в новый массив со здвигом
	for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];
	// Удаляем исходный массив
	delete[] arr;
	// Увеличиваем число строк
	rows++;
	// Возвращаем новый массив
	return buffer;
}
template <typename T>
void insert_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < index; j++)buffer[j] = arr[i][j];
		for (int j = index; j < cols; j++)buffer[j + 1] = arr[i][j];
		delete[]arr[i];
		arr[i] = buffer;
	}
	cols++;
}

template <typename T>
T* erase(T* arr, int& n, int value, int index)
{
	T* buffer = new T[n - 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = ++index; i < n; i++)buffer[i - 1] = arr[i];
	delete[] arr;
	n--;
	return buffer;
}

template <typename T>
T** erase_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index + 1; i < rows; i++)buffer[i - 1] = arr[i];
	delete[] arr;
	rows--;
	return buffer;
}

template <typename T>
void erase_col(T** arr, const int rows, int& cols, const int index)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < index; j++) buffer[j] = arr[i][j];
		for (int j = index + 1; j < cols; j++)buffer[j - 1] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
}


template <typename T>
T* pop_back(T* arr, int& n)
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
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
	//возврашает новый адресс массива
}

template <typename T>
T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

template <typename T>
void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++)buffer[j] = arr[i][j];
		delete arr[i];
		arr[i] = buffer;
	}
	cols--;
}

template <typename T>
T* pop_front(T* arr, int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
	//в новый массив копируем все элементы кроме удаляемого
}

template <typename T>
T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [--rows];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template <typename T>
void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1];
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j + 1];
		delete arr[i];
		arr[i] = buffer;
	}
	cols--;
}



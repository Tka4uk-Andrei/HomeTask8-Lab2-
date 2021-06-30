#include <iostream>
#include <string>
#include "tasks.h"
#include "matrix_input.h"
#include "matrix_output.h"

using namespace std;

/// <summary>
/// Вывод в консоль номера задания
/// </summary>
/// <param name="taskNum">Номер задания</param>
void printTaskNum(int taskNum)
{
	cout << "-----------\n";
	cout << "-- Task " << taskNum << "--\n";
	cout << "-----------\n";
}

/// <summary>
/// Вывод ответов на первое задание. В каких столбцах есть повторяющиеся элементы
/// </summary>
/// <param name="mes">Ответы на вопросы</param>
/// <param name="output">Куда выводить</param>
void printAns1(vector<string> mes, ostream& output)
{
	printTaskNum(1);

	int size = mes.size();
	for (int i = 0; i < size; ++i)
		output << mes[i];

	output << endl;
}

/// <summary>
/// Вывод ответа на второе задание. 
/// Каково количество локальных минимумов в матрице
/// </summary>
/// <param name="ans">Кол-во локальных минимумов</param>
/// <param name="output">Куда выводить</param>
void printAns2(int ans, ostream& output)
{
	printTaskNum(2);
	output << "Local minimum count in matrix is " << ans << endl;
}

/// <summary>
/// Выполнение задания 1. Вывод сообщений, в каких 
/// столбцах есть повторяющиеся элементы. Выполнение для
/// статической матрицы
/// </summary>
void executeTask1()
{
	Matrix matrix = StaticMatrixCreate();
	PrintMatrixParam(matrix, cout);
	cout << "Enter matrix\n";
	matrix = MatrixRead(matrix, cin);

	printAns1(Simmularity(matrix), cout);
}

/// <summary>
/// Выполнение задания 2. Вывод количества
/// локальных минимумов в матрице. 
/// Работа с динамической матрицей.
/// </summary>
void executeTask2()
{
	Matrix matrix;

	matrix = ConsoleRead();
	printAns2(LocalMinCount(matrix), cout);

	delete[] matrix.mat;
}
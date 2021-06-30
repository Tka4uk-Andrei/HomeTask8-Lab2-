#include <iostream>
#include <string>
#include "tasks.h"
#include "matrix_input.h"
#include "matrix_output.h"

using namespace std;

/// <summary>
/// ����� � ������� ������ �������
/// </summary>
/// <param name="taskNum">����� �������</param>
void printTaskNum(int taskNum)
{
	cout << "-----------\n";
	cout << "-- Task " << taskNum << "--\n";
	cout << "-----------\n";
}

/// <summary>
/// ����� ������� �� ������ �������. � ����� �������� ���� ������������� ��������
/// </summary>
/// <param name="mes">������ �� �������</param>
/// <param name="output">���� ��������</param>
void printAns1(vector<string> mes, ostream& output)
{
	printTaskNum(1);

	int size = mes.size();
	for (int i = 0; i < size; ++i)
		output << mes[i];

	output << endl;
}

/// <summary>
/// ����� ������ �� ������ �������. 
/// ������ ���������� ��������� ��������� � �������
/// </summary>
/// <param name="ans">���-�� ��������� ���������</param>
/// <param name="output">���� ��������</param>
void printAns2(int ans, ostream& output)
{
	printTaskNum(2);
	output << "Local minimum count in matrix is " << ans << endl;
}

/// <summary>
/// ���������� ������� 1. ����� ���������, � ����� 
/// �������� ���� ������������� ��������. ���������� ���
/// ����������� �������
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
/// ���������� ������� 2. ����� ����������
/// ��������� ��������� � �������. 
/// ������ � ������������ ��������.
/// </summary>
void executeTask2()
{
	Matrix matrix;

	matrix = ConsoleRead();
	printAns2(LocalMinCount(matrix), cout);

	delete[] matrix.mat;
}
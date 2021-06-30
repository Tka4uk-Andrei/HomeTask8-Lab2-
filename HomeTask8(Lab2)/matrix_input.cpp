#include <iostream>
#include "Errors.h"
#include "matrix_input.h"

/// <summary>
/// ������ ����������� �������, �� ������
/// </summary>
/// <param name="input">����� �� ��������, ���������� ����������</param>
/// <returns>
/// ������� � ����������� ���������� ������ � ������
/// </returns>
Matrix MatrixParamRead(std::istream &input) throw (std::string)
{
	int hight;
	int width;

	if (!(input >> width) || !(input >> hight) || width <= 0 || hight <= 0)
		throw MATRIX_SIZE_ERR;

	Matrix matrix;
	matrix.width = width;
	matrix.hight = hight;

	return matrix;
}

/// <summary>
/// �������� ������������ �������
/// </summary>
/// <param name="matrix">�������, � ������� �� ��������</param>
/// <returns>
/// ��������� ������������ �������
/// </returns>
Matrix DynMatrixCreate(Matrix matrix)
{
	matrix.mat = new int[matrix.hight * matrix.width];
	return matrix;
}

/// <summary>
/// �������� ����������� �������
/// </summary>
/// <returns>
/// ��������� ������������ �������
/// </returns>
Matrix StaticMatrixCreate()
{
	Matrix matrix;

	static int mat[MATRIX_WIDTH * MATRIX_HEIGHT];
	matrix.width = MATRIX_WIDTH;
	matrix.hight = MATRIX_HEIGHT;
	matrix.mat = mat;

	return matrix;
}

/// <summary>
/// ������ �������� �������, � ������� �������� �����������, �� ������
/// </summary>
/// <param name="matrix">������� � �������� ������� � �������</param>
/// <param name="input">����� �����</param>
/// <returns>
/// ��������� ����������� �������
/// </returns>
Matrix MatrixRead(Matrix matrix, std::istream& input) throw (std::string)
{
	for (int i = 0; i < matrix.hight; ++i)
	{
		for (int j = 0; j < matrix.width; ++j)
		{
			if (!(input >> matrix.mat[i * matrix.width + j]))
				throw MATRIX_VALUES_ERR;
		}
	}

	return matrix;
}

/// <summary>
/// ������ �������� � �������� ������� �� �������
/// </summary>
/// <returns>
/// ����������� �������
/// </returns>
Matrix ConsoleRead()
{
	std::cout << "Enter width and hight of matrix\n";
	auto matrix = MatrixParamRead(std::cin);

	matrix = DynMatrixCreate(matrix);

	std::cout << "Enter matrix values\n";
	matrix = MatrixRead(matrix, std::cin);

	return matrix;
}
#include <iostream>
#include "Errors.h"
#include "matrix_input.h"

/// <summary>
/// Чтение размерности матрицы, из потока
/// </summary>
/// <param name="input">Поток из которого, происходит считывание</param>
/// <returns>
/// Матрицу с заполнеными парамтрами высоты и ширины
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
/// Создание динамической матрицы
/// </summary>
/// <param name="matrix">матрица, в которой всё создаётся</param>
/// <returns>
/// Созданная динамическая матрица
/// </returns>
Matrix DynMatrixCreate(Matrix matrix)
{
	matrix.mat = new int[matrix.hight * matrix.width];
	return matrix;
}

/// <summary>
/// Создание статической матрицы
/// </summary>
/// <returns>
/// Созданная динамическая матрица
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
/// Чтение значений матрицы, у которой известна размерность, из потока
/// </summary>
/// <param name="matrix">Матрица с заданной высотой и шириной</param>
/// <param name="input">Поток ввода</param>
/// <returns>
/// Полностью заполненную матрицу
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
/// Чтение размеров и значений матрицы из консоли
/// </summary>
/// <returns>
/// Заполненную матрицу
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
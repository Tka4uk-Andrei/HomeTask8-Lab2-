#include <iostream>
#include "DataStruct.h"

/// <summary>
/// Вывод матрицы
/// </summary>
/// <param name="matrix">Матрица из которой берутся данные</param>
/// <param name="ostream">Поток в который выводяться данные</param>
void PrintMatrix(Matrix matrix, std::ostream& ostream)
{
	for (int i = 0; i < matrix.hight; ++i)
	{
		for (int j = 0; j < matrix.width; ++i)
			ostream << matrix.mat[i * matrix.width + j] << "\t";
		ostream << "\n";
	}
}

/// <summary>
/// Вывод размеров матрицы
/// </summary>
/// <param name="matrix">Матрица из которой берутся данные</param>
/// <param name="ostream">Поток в который выводяться данные</param>
void PrintMatrixParam(Matrix matrix, std::ostream& output)
{
	output << "Width: " << matrix.width << "\n"
		<< "Hight: " << matrix.hight << "\n";
}

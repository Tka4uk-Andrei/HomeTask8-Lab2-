#include <iostream>
#include "DataStruct.h"

/// <summary>
/// ����� �������
/// </summary>
/// <param name="matrix">������� �� ������� ������� ������</param>
/// <param name="ostream">����� � ������� ���������� ������</param>
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
/// ����� �������� �������
/// </summary>
/// <param name="matrix">������� �� ������� ������� ������</param>
/// <param name="ostream">����� � ������� ���������� ������</param>
void PrintMatrixParam(Matrix matrix, std::ostream& output)
{
	output << "Width: " << matrix.width << "\n"
		<< "Hight: " << matrix.hight << "\n";
}

#include <iostream>
#include <fstream>
#include "DataStruct.h"

Matrix MatrixParamRead(std::istream &input)
{
	int hight;
	int width;

	input >> width;
	input >> hight;

	Matrix matrix;
	matrix.width = width;
	matrix.hight = hight;

	return matrix;
}

Matrix DynMatrixCreate(Matrix matrix)
{
	matrix.mat = new int*[matrix.hight];
	for (int i = 0; i < matrix.hight; ++i)
		matrix.mat[i] = new int[matrix.width];

	return matrix;
}

Matrix MatrixRead(Matrix matrix, std::istream& input)
{
	for (int i = 0; i < matrix.hight; ++i)
		for (int j = 0; j < matrix.width; ++j)
			input >> matrix.mat[i][j];

	return matrix;
}

void PrintWidthHight(Matrix matrix, std::ostream& ostream)
{
	ostream << "Matrix width " << matrix.width << "\n";
	ostream << "Matrix hight " << matrix.hight << "\n";
}

void PrintMatrix(Matrix matrix, std::ostream& ostream)
{
	for (int i = 0; i < matrix.hight; ++i)
	{
		for (int j = 0; j < matrix.width; ++i)
			ostream << matrix.mat[i][j] << "\t";
		ostream << "\n";
	}
}

Matrix FileRead(char name[])
{
	std::ifstream input(name);
	
	auto matrix = MatrixParamRead(input);
	PrintWidthHight(matrix, std::cout);

	matrix = DynMatrixCreate(matrix);

	matrix = MatrixRead(matrix, input);
	PrintMatrix(matrix, std::cout);

	return matrix;
}

Matrix ConsoleRead()
{
	std::cout << "Enter width and hight of matrix\n";
	auto matrix = MatrixParamRead( std::cin);

	matrix = DynMatrixCreate(matrix);

	std::cout << "Enter matrix values\n";
	matrix = MatrixRead(matrix, std::cin);

	return matrix;
}
#include <iostream>
#include "tasks.h"
#include "DataStruct.h"
#include "matrixIO.h"

// TODO finish file read and random generation

using namespace std;

void PrintAns1(Matrix matrix, ostream& output)
{
	output << "------\n";
	output << "Task 1\n";
	output << "------\n";

	auto mes = Simmularity( matrix );

	int size = mes.size();
	for (int i = 0; i < size; ++i)
		output << mes[i];

	output << endl;
}

void PrintAns2(Matrix matrix, ostream& output)
{
	output << "------\n";
	output << "Task 2\n";
	output << "------\n";

	int ans = LocalMinCount(matrix);
	output << "Local minimum count in matrix is " << ans << endl;
}

int main()
{
	auto matrix = ConsoleRead();

	PrintAns1(matrix, cout);
	PrintAns2(matrix, cout);

	for (int i = 0; i < matrix.hight; ++i)
		delete[] matrix.mat[i];
	delete[] matrix.mat;

	return 0;
}

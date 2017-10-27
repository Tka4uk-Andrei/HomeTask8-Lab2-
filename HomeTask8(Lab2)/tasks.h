#include <iostream>
#include <vector>
#include <string>
#include "DataStruct.h"

// difficulty?
std::vector<std::string> Simmularity(const Matrix matrix)
{
	std::vector<std::string> messages;
	for (int i = 0; i < matrix.width; ++i)
	{
		bool repeatFlag = false;

		for (int j = 0; j < matrix.hight - 1 && !repeatFlag; ++j)
			for (int k = j + 1; k < matrix.hight; ++k)
				repeatFlag += matrix.mat[j][i] == matrix.mat[k][i];

		messages.push_back( std::to_string(i + 1) + ") has repeat " + (repeatFlag ? "yes" : "no") + "\n");
	}

	return messages;
}

bool isInArrBoards(int x, int y, int n, int m)
{
	return (0 <= x && x < n) && (0 <= y && y < m);
}

int LocalMinCount(Matrix matrix)
{
	int vx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };
	int vy[8] = { 1, 0, -1, 1, -1, 0, -1, 1 };

	int ans = 0;

	for (int i = 0; i < matrix.hight; ++i)
		for (int j = 0; j < matrix.width; ++j)
		{
			bool localMinFlag = true;
			for (int k = 0; k < 8 && localMinFlag; ++k)
			{
				int ni = i + vx[k];
				int nj = j + vy[k];
				if (isInArrBoards(ni, nj, matrix.hight, matrix.width))
					localMinFlag *= matrix.mat[i][j] < matrix.mat[ni][nj];
			}

			ans += localMinFlag;
		}

	return ans;
}
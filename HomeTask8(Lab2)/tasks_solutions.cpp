#include <iostream>
#include <vector>
#include <string>
#include "DataStruct.h"

/// <summary>
/// Сравнивает два элемента матрицы.
/// 1 - если первый элемент больше вторго
/// 0 - если оба равны
/// -1 - если первый меньше второго
/// </summary>
/// <param name="m">Матрица, в которой происходит сравнение</param>
/// <param name="i">строка первого элемента</param>
/// <param name="j">столбец первого элемента</param>
/// <param name="ni">строка второго элемента</param>
/// <param name="nj">столбец второго элемента</param>
/// <returns>
/// Возвращает
/// 1 - если первый элемент больше вторго
/// 0 - если оба равны
/// -1 - если первый меньше второго
/// </returns>
inline bool matrixElCmp(Matrix m, int i, int j, int ni, int nj)
{
	if (m.mat[i * m.width + j] > m.mat[ni * m.width + nj])
		return 1;
	if (m.mat[i * m.width + j] == m.mat[ni * m.width + nj])
		return 0;

	return -1;
}

/// <summary>
/// Поиск похожих элементов в столбцах матрицы
/// </summary>
/// <param name="matrix">Матрица, для котрой выполняется проверка</param>
/// <returns>
/// Сообщения содержащие ответ на вопрос для каждого столбца
/// </returns>
std::vector<std::string> Simmularity(Matrix matrix)
{
	std::vector<std::string> messages;
	for (int i = 0; i < matrix.width; ++i)
	{
		bool repeatFlag = false;

		for (int j = 0; j < matrix.hight - 1 && !repeatFlag; ++j)
			for (int k = j + 1; k < matrix.hight; ++k)
				repeatFlag += matrixElCmp(matrix, j, i, k, i) == 0;

		messages.push_back("Column " + std::to_string( i + 1 ) + ") has repeat " + (repeatFlag? "yes" : "no") + "\n" );
	}

	return messages;
}

/// <summary>
/// Проверка выхода за пределы матрицы
/// </summary>
/// <param name="x">столбец матрицы</param>
/// <param name="y">строка матрицы</param>
/// <param name="n">кол-во столбцов</param>
/// <param name="m">кол-во строк</param>
/// <returns>
/// истину, если координаты не вышли за пределы матрицы, иначе ложь
/// </returns>
inline bool isInArrBoards(int x, int y, int n, int m)
{
	return (0 <= x && x < n) && (0 <= y && y < m);
}

/// <summary>
/// Считает количество локальных минимумов в матрице.
/// </summary>
/// <param name="matrix">Матрица, для котрой вычисляется кол-во</param>
/// <returns>
/// Кол-во локальных минимумов
/// </returns>
int LocalMinCount(Matrix matrix)
{
	int vx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
	int vy[8] = {1, 0, -1, 1, -1, 0, -1, 1};

	int ans = 0;

	for (int i = 0; i < matrix.hight; ++i)
		for (int j = 0; j < matrix.width; ++j)
		{
			// there could be perfomace improvement
			bool localMinFlag = true;
			for (int k = 0; k < 8 && localMinFlag; ++k)
			{
				int ni = i + vx[k];
				int nj = j + vy[k];
				// too much function calls
				if (isInArrBoards( ni, nj, matrix.hight, matrix.width ))
					localMinFlag *= matrixElCmp( matrix, i, j, ni, nj ) == -1;
			}

			ans += localMinFlag;
		}

	return ans;
}
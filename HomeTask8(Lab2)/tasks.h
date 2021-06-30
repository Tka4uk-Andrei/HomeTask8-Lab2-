#include <vector>
#include "DataStruct.h"

/// <summary>
/// Поиск похожих элементов в столбцах матрицы
/// </summary>
/// <param name="matrix">Матрица, для котрой выполняется проверка</param>
/// <returns>
/// Сообщения содержащие ответ на вопрос для каждого столбца
/// </returns>
std::vector<std::string> Simmularity(const Matrix matrix);

/// <summary>
/// Считает количество локальных минимумов в матрице.
/// </summary>
/// <param name="matrix">Матрица, для котрой вычисляется кол-во</param>
/// <returns>
/// Кол-во локальных минимумов
/// </returns>
int LocalMinCount(Matrix matrix);
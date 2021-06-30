#include "DataStruct.h"

int const MATRIX_WIDTH = 3;
int const MATRIX_HEIGHT = 4;

/// <summary>
/// Чтение размерности матрицы, из потока
/// </summary>
/// <param name="input">Поток из которого, происходит считывание</param>
/// <returns>
/// Матрицу с заполнеными парамтрами высоты и ширины
/// </returns>
Matrix MatrixParamRead(std::istream &input) throw (std::string);

/// <summary>
/// Создание статической матрицы
/// </summary>
/// <returns>
/// Созданная динамическая матрица
/// </returns>
Matrix StaticMatrixCreate();

/// <summary>
/// Чтение значений матрицы, у которой известна размерность, из потока
/// </summary>
/// <param name="matrix">Матрица с заданной высотой и шириной</param>
/// <param name="input">Поток ввода</param>
/// <returns>
/// Полностью заполненную матрицу
/// </returns>
Matrix MatrixRead(Matrix matrix, std::istream& input) throw (std::string);

/// <summary>
/// Чтение размеров и значений матрицы из консоли
/// </summary>
/// <returns>
/// Заполненную матрицу
/// </returns>
Matrix ConsoleRead();
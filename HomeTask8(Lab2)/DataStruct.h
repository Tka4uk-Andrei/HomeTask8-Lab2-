#pragma once

/// <summary>
/// Структура содержащая размеры матрицы, и ссылку на первый элемент
/// </summary>
struct Matrix
{
	int hight = -1;
	int width = -1;
	int* mat;
};
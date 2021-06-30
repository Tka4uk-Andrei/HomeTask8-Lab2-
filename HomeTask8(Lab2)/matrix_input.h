#include "DataStruct.h"

int const MATRIX_WIDTH = 3;
int const MATRIX_HEIGHT = 4;

/// <summary>
/// ������ ����������� �������, �� ������
/// </summary>
/// <param name="input">����� �� ��������, ���������� ����������</param>
/// <returns>
/// ������� � ����������� ���������� ������ � ������
/// </returns>
Matrix MatrixParamRead(std::istream &input) throw (std::string);

/// <summary>
/// �������� ����������� �������
/// </summary>
/// <returns>
/// ��������� ������������ �������
/// </returns>
Matrix StaticMatrixCreate();

/// <summary>
/// ������ �������� �������, � ������� �������� �����������, �� ������
/// </summary>
/// <param name="matrix">������� � �������� ������� � �������</param>
/// <param name="input">����� �����</param>
/// <returns>
/// ��������� ����������� �������
/// </returns>
Matrix MatrixRead(Matrix matrix, std::istream& input) throw (std::string);

/// <summary>
/// ������ �������� � �������� ������� �� �������
/// </summary>
/// <returns>
/// ����������� �������
/// </returns>
Matrix ConsoleRead();
#include <vector>
#include "DataStruct.h"

/// <summary>
/// ����� ������� ��������� � �������� �������
/// </summary>
/// <param name="matrix">�������, ��� ������ ����������� ��������</param>
/// <returns>
/// ��������� ���������� ����� �� ������ ��� ������� �������
/// </returns>
std::vector<std::string> Simmularity(const Matrix matrix);

/// <summary>
/// ������� ���������� ��������� ��������� � �������.
/// </summary>
/// <param name="matrix">�������, ��� ������ ����������� ���-��</param>
/// <returns>
/// ���-�� ��������� ���������
/// </returns>
int LocalMinCount(Matrix matrix);
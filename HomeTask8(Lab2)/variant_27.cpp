#include <iostream>
#include <string>
#include "task_execution.h"

using namespace std;

int main()
{
	try
	{
		executeTask1();
		executeTask2();
	}
	catch (string errMes)
	{
		cout << errMes << "\n";
		cout << "Program is closing..." << endl;
		return 0;
	}

	return 0;
}
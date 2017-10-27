#pragma once

struct Matrix
{
	int hight = -1;
	int width = -1;
	int** mat;
};

enum InputType {console = 1, file = 2, random = 3};

const std::string INPUT_FILE = "input.in";
const std::string OUTPUT_FILE = "input.out";
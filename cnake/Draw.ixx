#include <Windows.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

export module Draw;

import cst;
import Block;
import std;

export void draw(const std::list<Block>& snake, Block& apple)
{
	static bool first_try = true;
	static HANDLE stdh = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string output((cst::board_x_size)*cst::board_y_size, ' ');
	if (apple.getX() < cst::board_x_size)
		output[apple.getX() + apple.getY() * cst::board_x_size] = cst::apple_symbol;
	for (Block tmp : snake)
		output[tmp.getX() + tmp.getY() * cst::board_x_size] = cst::snake_symbol;
	if (first_try)
	{
		first_try = false;
		CONSOLE_CURSOR_INFO structCursorInfo;
		GetConsoleCursorInfo(stdh, &structCursorInfo);
		structCursorInfo.bVisible = FALSE;
		SetConsoleCursorInfo(stdh, &structCursorInfo);
	}
	SetConsoleCursorPosition(stdh, {0, 0});
	std::string real_output((cst::board_x_size + 2) * (cst::board_y_size + 2), ' ');
	for (std::uint32_t i = 0; i < cst::board_y_size + 2; ++i)
		for (std::uint32_t j = 0; j < cst::board_x_size + 2; ++j)
			if (i == 0 || j == 0 || i == cst::board_y_size + 1 || j == cst::board_x_size + 1)
				real_output[i * (cst::board_x_size + 2) + j] = cst::board_symbol;
			else real_output[i * (cst::board_x_size + 2) + j] = output[(i - 1) * cst::board_x_size + (j - 1)];
	std::cout << real_output;
}

export void draw(const std::list<Block>& snake, Block& apple, bool flag)
{

}
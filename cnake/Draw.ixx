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
	static std::string last_state;
	static HANDLE stdh = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string output(cst::board_x_size * cst::board_y_size, ' ');
	if (apple.getX() < cst::board_x_size)
		output[apple.getX() + apple.getY() * cst::board_x_size] = cst::apple_symbol;
	for (Block tmp : snake)
		output[tmp.getX() + tmp.getY() * cst::board_x_size] = cst::snake_symbol;
	if (first_try)
	{
		first_try = false;
		last_state = output;
		std::cout << output;
	}
	std::uint8_t counter = 0;
	for (std::uint32_t i = 0; i < output.size(); ++i)
		if (output[i] != last_state[i])
		{
			++counter;
			if (counter > cst::draw_const)
				break;
		}
	if (counter > cst::draw_const)
	{
		system("cls");
		std::cout << output;
	}
	else {
		COORD c;
		std::uint8_t local_counter = 0;
		for (std::uint32_t i = 0; i < output.size() && local_counter < counter; ++i)
			if (output[i] != last_state[i])
			{
				++local_counter;
				c.X = i % cst::board_x_size;
				c.Y = i / cst::board_x_size;
				SetConsoleCursorPosition(stdh, c);
				if (last_state[i] == cst::snake_symbol)
					std::cout << ' ';
				else if (output[i] == cst::apple_symbol)
					std::cout << cst::apple_symbol;
				else std::cout << cst::snake_symbol;
			}
	}
	last_state = output;
}

export void draw(const std::list<Block>& snake, Block& apple, bool flag)
{

}
export module Draw;

import cst;
import Block;
import std;

export void draw(const std::list<Block>& snake, Block& apple)
{
	std::string output(cst::board_x_size * cst::board_y_size, ' ');
	if (apple.getX() < cst::board_x_size)
		output[apple.getX() + apple.getY() * cst::board_x_size] = cst::apple_symbol;
	for (Block tmp : snake)
		output[tmp.getX() + tmp.getY() * cst::board_x_size] = cst::snake_symbol;
	std::cout << output;
}

#include <list>
#include <conio.h>
#include <random>
#include <ctime>
#include <string>

export module Snake;

import Block;
import cst;

export class Snake {
public:
	Snake()
	{
		body.push_back(Block{ cst::board_x_size - 1, cst::board_y_size });
		body.push_back(Block{ cst::board_x_size, cst::board_y_size });
		body.push_back(Block{ cst::board_x_size + 1, cst::board_y_size });
		way = left;
	}
	bool step()
	{

	}
	void getStr(std::string& output)
	{
		for (Block block : body)
			output[block.getY() * cst::board_x_size + block.getX()] = cst::snake_symbol;
	}
private:
	std::list<Block> body;
	enum {
		up = 0,
		left = 1,
		down = 2,
		right = 3
	}way;
};
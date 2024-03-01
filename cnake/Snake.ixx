#include <list>
#include <vector>
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
		if (_kbhit())
			if (_getch() == -24)
				way = (Way)_getch();
		switch (way) {
		case up:
			if (body.front().getY() == 0)
				return false;
			body.push_front(Block{ body.front().getX(), body.front().getY() - 1 });
			break;
		case down:
			if (body.front().getY() == cst::board_y_size - 1)
				return false;
			body.push_front(Block{ body.front().getX(), body.front().getY() + 1 });
			break;
		case left:
			if (body.front().getX() == 0)
				return false;
			body.push_front(Block{ body.front().getX() - 1, body.front().getY() });
			break;
		case right:
			if (body.front().getX() == cst::board_x_size)
				return false;
			body.push_front(Block{ body.front().getX() + 1, body.front().getY() });
			break;
		}
		old_back = body.back();
		body.pop_back();
		return true;
	}
	void return_back() {
		body.push_back(old_back);
	}
	void draw(std::string& output)
	{
		for (Block block : body)
			output[block.getY() * cst::board_x_size + block.getX()] = cst::snake_symbol;
	}
	std::vector<Block>& get_available_places()
	{
		std::vector<Block> available_places;
			for (uint32_t i = 0; i < cst::board_y_size; ++i)
				for (uint32_t j = 0; j < cst::board_x_size; ++j)
				{
					bool isAvailable = true;
					for (Block block : body)
						if (i == block.getY() && j == block.getX())
						{
							isAvailable = false;
							break;
						}
					if (isAvailable)
						available_places.push_back(Block{ j, i });
				}
	}
	Block getHeadCoord()
	{
		return body.front();
	}
private:
	Block old_back;
	std::list<Block> body;
	enum Way {
		up = 80,
		left = 77,
		down = 72,
		right = 75
	}way;
};
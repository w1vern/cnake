#include <vector>
#include <iostream>

export module Board;

import Snake;
import Apple;
import Block;
import cst;

export class Board {
public:
	Board() {}
	bool step()
	{
		std::string output(cst::board_x_size * cst::board_y_size, ' ');
		snake.step();
		if (apple.Exists())
		{
			if (snake.getHeadCoord().getX() == apple.getAppleCoord().getX() 
				&& snake.getHeadCoord().getY() == apple.getAppleCoord().getY())
			{
				apple.dead();
				snake.return_back();
			}
			std::vector<Block> available_places = snake.get_available_places();
			apple.make_apple(available_places);
			apple.draw(output);
		}
		snake.draw(output);
		std::cout << output;
		return true;
	}
private:
	Snake snake;
	Apple apple;
};
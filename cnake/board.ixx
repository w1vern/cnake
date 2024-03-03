export module Board;

import Draw;
import Snake;
import Apple;
import Block;
import cst;

import std;

export class Board {
public:
	Board() {}
	bool step()
	{
		if (!snake.step())
			return false;
		if (apple.Exists())
		{
			if (snake.getHeadCoord().getX() == apple.getAppleCoord().getX() 
				&& snake.getHeadCoord().getY() == apple.getAppleCoord().getY())
			{
				apple.dead();
				snake.return_back();
			}
			std::vector<Block> available_places;
			snake.get_available_places(available_places);
			apple.make_apple(available_places);
		}
		draw(snake.draw(), apple.draw());
		return true;
	}
private:
	Snake snake;
	Apple apple;
};
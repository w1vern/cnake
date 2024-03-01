#include <conio.h>

export module Snake;

import Block;
import cst;

import std;

void checker(bool& key, bool& game_flag)
{
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
		if (_kbhit())
			key = true;
	}
}

export class Snake {
public:
	Snake()
	{
		body.push_back(Block{ cst::board_x_size / 2 - 1, cst::board_y_size / 2 });
		body.push_back(Block{ cst::board_x_size / 2, cst::board_y_size / 2 });
		body.push_back(Block{ cst::board_x_size / 2 + 1, cst::board_y_size / 2 });
		way = left;
		key_was_pushed = false;
		game_flag = true;
		std::thread thr(checker, std::ref(key_was_pushed), std::ref(game_flag));
		/*thr.detach();*/
	}
	~Snake()
	{
		game_flag = false;
	}
	bool step()
	{
		if (key_was_pushed)
		{
			int inp = _getch();
			if (inp == up || inp == down || inp == left || inp == right)
				way = (Way)inp;
			key_was_pushed = false;
		}
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
			if (body.front().getX() == cst::board_x_size - 1)
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
		for (Block block : body) {
			/*std::cout << block.getX() << std::endl;
			std::cout << block.getY();*/
			output[block.getY() * cst::board_x_size + block.getX()] = cst::snake_symbol;
		}
	}
	void get_available_places(std::vector<Block>& available_places)
	{
		for (std::uint32_t i = 0; i < cst::board_y_size; ++i)
			for (std::uint32_t j = 0; j < cst::board_x_size; ++j)
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
		up = 'w',
		left = 'a',
		down = 's',
		right = 'd'
	}way;
	bool key_was_pushed;
	bool game_flag;
};
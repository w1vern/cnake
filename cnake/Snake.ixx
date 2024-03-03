export module Snake;

import Block;
import cst;
import Input;

import std;

export class Snake {
public:
	Snake()
	{
		for (std::uint32_t i = 0; i < cst::snakeBodySize + 2; ++i)
		{
			body.push_back(Block{ cst::board_x_size / 2 + 
				static_cast<std::uint32_t>(std::ceil(i - std::ceil(static_cast<float>(cst::snakeBodySize) / 2))),
				cst::board_y_size / 2});
		}
		way = cst::start_way;
	}
	bool step()
	{
		input(way);
		Block front;
		switch (way) {
		case cst::up:
			if (body.front().getY() == 0)
				return false;
			front = Block{ Block{ body.front().getX(), body.front().getY() - 1 } };
			break;
		case cst::down:
			if (body.front().getY() == cst::board_y_size - 1)
				return false;
			front = Block{ Block{ body.front().getX(), body.front().getY() + 1 } };
			break;
		case cst::left:
			if (body.front().getX() == 0)
				return false;
			front = Block{ Block{ body.front().getX() - 1, body.front().getY() } };
			break;
		case cst::right:
			if (body.front().getX() == cst::board_x_size - 1)
				return false;
			front = Block{ Block{ body.front().getX() + 1, body.front().getY() } };
			break;
		}
		for (Block tmp : body)
			if (tmp.getX() == front.getX() && tmp.getY() == front.getY())
				return false;
		body.push_front(front);
		old_back = body.back();
		body.pop_back();
		return true;
	}
	void return_back() {
		body.push_back(old_back);
	}
	const std::list<Block>& draw()
	{
		return body;
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
	cst::Way way;
};
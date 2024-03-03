export module Apple;

import Block;
import cst;

import std;

export class Apple {
public:
	Apple()
	{
		body = Block{ cst::board_x_size, cst::board_y_size };
		needToCreate = false;
		isExists = false;
		std::srand(std::time(nullptr));
	}
	void make_apple(std::vector<Block>& available_places)
	{
		if (needToCreate)
		{
			std::uint32_t len = available_places.size();
			std::uint32_t index = std::rand() % len;
			body = Block{ available_places[index].getX(), available_places[index].getY() };
			needToCreate = false;
		}
	}
	bool Exists()
	{
		if (isExists)
			return true;
		if (std::rand() % 100 < cst::spawn_chance * 100)
		{
			isExists = true;
			needToCreate = true;
		}
		return isExists;
	}
	Block& draw()
	{
		return body;
	}
	Block getAppleCoord()
	{
		return body;
	}
	void dead()
	{
		isExists = false;
		body = Block{ cst::board_x_size, cst::board_y_size };
	}
private:
	Block body;
	bool isExists;
	bool needToCreate;
};
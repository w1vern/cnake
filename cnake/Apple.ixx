#include <vector>
#include <random>
#include <ctime>

export module Apple;

import Block;
import cst;

export class Apple {
public:
	Apple() 
	{
		isExists = false;
		std::srand(std::time(nullptr));
	}
	void make_apple(std::vector<Block>& available_places) 
	{
		uint32_t len = available_places.size();
		uint32_t index = std::rand() % len;
		body = Block{ available_places[index].getX(), available_places[index].getY() };
	}
	bool Exists()
	{
		if (isExists)
			return true;
		if (std::rand() % 100 < cst::spawn_chance * 100)
			isExists = true;
		return isExists;
	}
	void draw(std::string& output)
	{
		output[body.getX() + body.getY() * cst::board_x_size] = cst::apple_symbol;

	}
	Block getAppleCoord()
	{
		return body;
	}
	void dead()
	{
		isExists = false;
	}
private:
	Block body;
	bool isExists;
};
#include <iostream>

export module Block;

export class Block {
public:
	Block() {}
	Block(uint32_t x, uint32_t y) : x(x), y(y) {}
	void operator=(const Block& block)
	{
		this->x = block.x;
		this->y = block.y;
	}
	/*bool operator==(Block block)
	{
		if (this->x == block.x && this->y == block.y)
			return true;
		return false;
	}*/
	uint32_t getX() { return x; }
	uint32_t getY() { return y; }
private:
	uint32_t x;
	uint32_t y;
};
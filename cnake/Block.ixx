export module Block;

import std;

export class Block {
public:
	Block() {}
	Block(std::uint32_t x, std::uint32_t y) : x(x), y(y) {}
	void operator=(const Block& block)
	{
		this->x = block.x;
		this->y = block.y;
	}
	/*bool operator==(const Block& block)
	{
		if (this->x == block.x && this->y == block.y)
			return true;
		return false;
	}*/
	std::uint32_t getX() { return x; }
	std::uint32_t getY() { return y; }
private:
	std::uint32_t x;
	std::uint32_t y;
};
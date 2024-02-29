#include <iostream>

export module Block;

export class Block{
public:
	Block(uint8_t x, uint8_t y) : x(x), y(y) {}
	uint8_t getX() { return x; }
	uint8_t getY() { return y; }
private:
	uint8_t x;
	uint8_t y;
};
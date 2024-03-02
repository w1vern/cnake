#include <Windows.h>

export module cst;


import std;

export namespace cst {
	std::uint32_t board_x_size;
	std::uint32_t board_y_size;
	std::uint32_t frameRate;
	std::uint32_t frameTime;
	float spawn_chance;
	char snake_symbol;
	char apple_symbol;
	void calc() {
		HANDLE stdh = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(stdh, &csbi);
		board_x_size = csbi.srWindow.Right - csbi.srWindow.Left + 1;
		board_y_size = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

		frameRate = 15;
		frameTime = 1000 / frameRate;
		spawn_chance = 0.5 / frameRate;
		snake_symbol = '^';
		apple_symbol = '@';
	}
};
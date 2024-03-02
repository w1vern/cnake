

export module Game;

import cst;
import Board;

import std;

export void game()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	cst::calc();
	Board board;

	bool game_flag = true;
	while (game_flag)
	{
		std::clock_t start = std::clock();
		game_flag = board.step();
		std::clock_t time = std::clock() - start;
		if (time < cst::frameTime)
			std::this_thread::sleep_for(std::chrono::milliseconds(cst::frameTime - time));
	}

}

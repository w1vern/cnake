#include <Windows.h>

export module Game;

import cst;
import Board;

import std;

export void game()
{
	bool game_flag = true;
	while (game_flag)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		cst::calc();

		Board board;
		bool session_flag = true;
		while (session_flag)
		{
			std::clock_t start = std::clock();
			session_flag = board.step();
			std::clock_t time = std::clock() - start;
			if (time < cst::frameTime)
				std::this_thread::sleep_for(std::chrono::milliseconds(cst::frameTime - time));
		}
		system("cls");
		std::cout << "YOU LOST!";
	}
}

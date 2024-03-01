export module Game;

import cst;
import Board;

export void game() 
{
	cst::calc();
	Board board;

	bool game_flag = true;
	while (game_flag)
	{
		game_flag = board.step();
	}

}

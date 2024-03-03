#include <conio.h>

export module Input;

import cst;

export void input(cst::Way& way)
{
	if (_kbhit())
	{
		int inp = _getch();
		if (inp == cst::up || inp == cst::down || inp == cst::left || inp == cst::right)
			way = (cst::Way)inp;
	}
}
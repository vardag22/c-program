#include "calc.h"
#include <cstdlib>
#include <iostream>
#include <termios.h>
#define PROGRAM_SUCCESS 0

/* ======== Simple Percentage Calculating Program (Robost) ========= */

int main()
{
	#if defined(_WIN32)
		std::system("cls");
	#else
		std::system("clear");
	#endif

	do {
		printFinalResult();
		std::cout << '\n'; 
	} while (getChoiceFromUser());

	return PROGRAM_SUCCESS;
}
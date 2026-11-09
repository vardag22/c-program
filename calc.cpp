#include "calc.h"
#include <iostream>
#include <string_view>
#include <limits>
#define PROGRAM_SUCCESS 0

/* ======== Simple Percentage Calculating Program (Robust) ========= */

double getInputFromUser(std::string_view sv)
{
	auto getNumbers{0.0};
	while (true)
	{
		std::cout << "Enter " << sv << " numbers: ";

		if (std::cin >> getNumbers)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return getNumbers;
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "Invalid! Please enter a numeric type!\n";
	}
}

double calculatePercentage()
{
	auto totalNumbers{0.0};
	while (true)
	{
		totalNumbers = getInputFromUser("total");

		if (totalNumbers != 0.0)
			break;

		std::cerr << "Can't perform division by 0!\n";
	}

	auto obtainNumbers{0.0};
	while (true)
	{
		obtainNumbers = getInputFromUser("obtain");
		if (obtainNumbers <= totalNumbers)
			break;

		std::cerr << "Obtained numbers must be less than or equal to total numbers!\n";
	}

	auto result{obtainNumbers / totalNumbers * 100};
	return result;
}

bool getChoiceFromUser()
{
	char getChoice{};
	while(true)
	{
		std::cout << "Do you want to calculate again (y/n): ";

		if (std::cin >> getChoice)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			
			// Handle both uppercase and lowercase inputs cleanly
			switch (getChoice)
			{
				case 'y': case 'Y': return true;
				case 'n': case 'N': return false;
				default:
					std::cerr << "Invalid choice! Please enter 'y' or 'n'.\n";
					continue;
			}
		}	

		// Handle stream state failures
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cerr << "Input reading error. Try again.\n";
	}
}

void printFinalResult()
{
	auto result{calculatePercentage()};
	std::cout << "Your percentage is: " << result << "%\n";
}
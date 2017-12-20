#include "ParseFile.h"

void runParseFile()
{
	string filename = "bin/stats.txt";
	ifstream input;

	input.open(filename);

	if (!input.is_open())
	{
		return;
	}

	while (input)
	{
		string line;
		getline(input, line, ':');

		int population;
		input >> population;

		// PROBLEM 1 - extra newline gets printed as part of the next cout statement. We need to get the character and discard.
		input.get(); // old
		input >> ws; // C++11 - read all the whitespace.

		// PROBLEM 2 - we get a malformed output if we don't keep checking for an error state. If there is nothing more to read
		// and we continue parsing, cout << population will give the last int that it successfully read.
		if (!input)
		{
			break;
		}

		cout << "'" << line << "' -- '" << population << "'" << endl;
	}

	input.close();
}
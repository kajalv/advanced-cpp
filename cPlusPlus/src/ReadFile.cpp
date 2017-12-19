#pragma once

#include "ReadFile.h"

void runReadFile()
{
	string inFileName = "bin/read.txt";
	ifstream inFile; // or fstream, and specify mode ios::in while opening

	inFile.open(inFileName);

	if (inFile.is_open())
	{
		cout << "Reading from file:" << endl;

		string line;
		inFile >> line; // this operator will only read one word at a time - not the whole line - whitespace is delimiter
		cout << line << endl;

		while (!inFile.eof()) // can also say just while (inFile) because the not/bool operator is overloaded
		{
			getline(inFile, line);
			cout << line << endl;
		}
		
		inFile.close(); // do not forget!
		cout << "Read from file." << endl;
	}
	else
	{
		cout << "Cannot open file: " << inFileName << endl;
	}
}
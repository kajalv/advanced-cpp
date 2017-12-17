#include "CreateFile.h"

void createWithOfstream()
{
	ofstream outFile;
	string ofName = "bin/testOF.txt";

	outFile.open(ofName); // no mode specified

	if (outFile.is_open()) // check if open
	{
		outFile << "Hello there" << endl;
		outFile << 123 << endl;
		outFile.close(); // flushes
		cout << "Created file " << ofName << endl;
	}
	else
	{
		cout << "Could not create file: " << ofName << endl;
	}
}

void createWithFstream()
{
	fstream outFile;
	string ofName = "bin/testF.txt";

	outFile.open(ofName, ios::out); // Specify the output mode

	if (outFile.is_open()) // check if open
	{
		outFile << "Hello there" << endl;
		outFile << 123 << endl;
		outFile.close(); // flushes
		cout << "Created file " << ofName << endl;
	}
	else
	{
		cout << "Could not create file: " << ofName << endl;
	}
}

void runCreateFile()
{
	createWithOfstream();
	createWithFstream();
}
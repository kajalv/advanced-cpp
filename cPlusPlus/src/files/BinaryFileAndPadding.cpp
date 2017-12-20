#include "BinaryFileAndPadding.h"

// C++ pads structs to make it more efficient to transfer to and from memory.

struct PersonPadded
{
	// string name; -- CANNOT BE USED when writing this struct to a binary file.
	// objects of string class contain pointers. Text is not stored directly in the variable (stack)
	// but instead, allocated on the heap with 'new' operator.
	// So we only write a pointer to the text into the binary file. It allocates extra memory to store the actual text.
	// Next time it is loaded, it points nowhere.

	char name[50]; // 50 bytes
	int age; // 4 bytes
	double weight; // 8 bytes
	// char c; -- even on adding, size remains 64 bytes, because of padding
};

// Need to turn off padding to write to a file
// Preprocessor directive. This has a 'stack-like' structure.

// 1 says align the data in whatever follows in single-byte boundaries. If we increase the boundary, we get padding in the struct
// i.e. Make packing align on byte boundaries - means no padding
#pragma pack(push, 1)

struct PersonNotPadded
{
	char name[50];
	int age;
	double weight;
};

// undo the directive so it doesn't apply to whatever comes after it
#pragma pack(pop)

void checkPadding()
{
	cout << "Size of 'Person' with padding: " << sizeof(PersonPadded) << " bytes" << endl;
	cout << "Size of 'Person' without padding: " << sizeof(PersonNotPadded) << " bytes" << endl;
}

void runBinaryFile()
{

	PersonNotPadded someone = {"Frodo", 22, 60.0};

	string filename = "bin/test.bin";

	// write binary file 

	ofstream outputFile;

	outputFile.open(filename, ios::binary); // this is important. Default is text file format, C++ will translate newlines as appropriate

	// if using fstream:
	// outputFile.open(filename, ios::binary|ios::out); // bitwise OR operator, because both modes are required

	if (outputFile.is_open())
	{
		// write needs a char pointer pointing to some data

		// old way
		// outputFile.write((char *)&someone, sizeof(PersonNotPadded));

		// new way, considered better
		outputFile.write(reinterpret_cast<char *>(&someone), sizeof(PersonNotPadded));

		outputFile.close();
	}
	else
	{
		cout << "Could not create file: " << filename << endl;
	}

	// read binary stream

	PersonNotPadded someoneElse = {};

	ifstream inputFile;

	inputFile.open(filename, ios::binary); // mode required

	if (inputFile.is_open())
	{
		inputFile.read(reinterpret_cast<char *>(&someoneElse), sizeof(PersonNotPadded));

		inputFile.close();
	}
	else
	{
		cout << "Could not open file: " << filename << endl;
	}

	cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.weight << endl;
}
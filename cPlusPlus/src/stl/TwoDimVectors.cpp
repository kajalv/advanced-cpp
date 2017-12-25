#include "TwoDimVectors.h"

void run2DVectors()
{
	// 2D vector with 3 rows and 4 columns
	// need to give a space when initializing inner vector as it does not work on all compilers, so good practice
	vector< vector<int> > grid(3, vector<int>(4, 7));

	grid[1].push_back(8); // each row itself is resizeable because it is a vector!

	for (unsigned int row = 0; row < grid.size(); row++)
	{
		for (unsigned int col = 0; col < grid[row].size(); col++)
		{
			cout << grid[row][col] << flush; // cout flush
		}
		cout << endl;
	}
}
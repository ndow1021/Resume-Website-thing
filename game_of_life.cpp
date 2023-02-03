/**
 * ECE 260: Lab #1 - Game of Life
 **/

/**
 * Include all the necessary libraries
 **/
// TODO: Question #1 - What is the purpose of these statements?
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;


/**
 * Define the value ALIVE or DEAD to be true/false
 * Instead of typing 'true' and 'false' throughout 
 * your code, you should instead use 'ALIVE' and 'DEAD'
 **/
#define ALIVE true
#define DEAD false

/**
 * Define icons for ALIVE or DEAD (these are printed by printGrid)
 * Instead of typing '#' and '.' throughout your code, 
 * you should instead use 'ALIVE_ICON' and 'DEAD_ICON'
 **/
#define ALIVE_ICON '#'
#define DEAD_ICON '.'

/**
 * Define static global variables
 **/
// TODO: Question #2 - What is the purpose of the const modifier? How about the static modifier?
const static int generations = 2;
const static int depth = 4;
const static int width = 7;



/**
 * Print out the game of life grid, row by row
 **/
void printGrid(bool** grid)
{
	// TODO: Task #3 - implement this function;
	// it should iterate over the 2-D grid and print out the appropriate icons.
	// Do NOT use 'true'/'false' or '0'/'1' to indicate a true/false state. Instead,
	// utilize the #define statements from lines 21-22.  Use ALIVE to indicate true and
	// DEAD to indicate false.
	//
	// YOUR CODE HERE

	// END YOUR CODE
}



/**
 * For a given position grid[x][y] count the number of adjacent neighbors
 **/
int countNeighbors(bool** grid, int x, int y)
{
	int count = 0;

	cout << "For " << x << "," << y << endl;
	for (int deltaX = -1; deltaX <= 1; deltaX++)
	{
		for (int deltaY = -1; deltaY <= 1; deltaY++)
		{
			int xPrime = x + deltaX;
			int yPrime = y + deltaY;

			// TODO: Question #3 - Why is this if-statement required? What does it do?
			if (xPrime >= 0 && xPrime < width && yPrime >= 0 && yPrime < depth)
			{
				if (!(x == xPrime && y == yPrime))  // ignore self, only count neighbors
				{
					if (grid[xPrime][yPrime] == ALIVE)
					{
						count++;
						cout << "\t" << xPrime << "," << yPrime << " is alive" << endl;
					}
					else
					{
						cout << "\t" << xPrime << "," << yPrime << " is dead" << endl;
					}
				}
			}
		}
	}
	return count;
}



/**
 * Evolve the future grid based upon the state of the current grid.
 **/
void evolve(bool** current, bool** future)
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < depth; y++)
		{
			int count = countNeighbors(current, x, y);

			// TODO: Task #4 - use the cell value for current[x][y] and the number of 
			// neighbors to determine the value of future[x][y].
			// The number of neighbors is already stored in the variable named count.
			// Do NOT use 'true'/'false' or '0'/'1' to indicate a true/false state. Instead,
			// utilize the #define statements from lines 21-22.  Use ALIVE to indicate true and
			// DEAD to indicate false.
			//
			// YOUR CODE HERE

			// END YOUR CODE
		}
	}
}



int main()
{
	/**
	 * Initializes the random number generator with a unique seed
	 **/
	// TODO: Question #4 - What is the srand function and why it is seeded with time(null)?
	srand(time(NULL));

	/**
	 * Creates 2D array of booleans...
	 * Start with the pointer** which is a pointer to an array of pointers
	 * 
	 * In this case, currentGrid is a pointer that points to an array of 
	 * pointers. Each index in that array of pointers points to another 
	 * array of bool values. Of course, the two lines of code below just
	 * declare that you want this structure in memory. They don't actually
	 * allocate the memory for any of the arrays.
	 * currentGrid* -> [*] [*] [*] [*] [*] [*] [*]
	 *                  |   |   |   |   |   |   |
	 *                  v   v   v   v   v   v   v 
	 *                 [f] [f] [t] [t] [f] [f] [t]
	 *                 [f] [f] [t] [f] [f] [f] [f]
	 *                 [f] [f] [t] [t] [t] [f] [f]
	 *                 [f] [t] [t] [f] [t] [f] [f]
	 **/
	bool** currentGrid;
	bool** futureGrid;

	/**
	 * Initializes the array of pointers for each grid. Utilizes two different grids
	 * to point towards "new" and "current/old" grids. This is where the first arrays
	 * in the 2D array structures is created in memory. The keyword "new" allocates
	 * memory.
	 **/
	// TODO: Question #5 - What type of objects are in the currentGrid and futureGrid arrays?
	currentGrid = new bool*[width];
	futureGrid = new bool*[width];

	/**
	 * Walk through the grid initializing each individual array element.
	 * This for-loop iterates over the first array in the 2D array structure
	 * that we just created. 
	 **/
	for (int x = 0; x < width; x++)
	{
		// TODO: Task #1 - initialize each boolean array
		// Read http://www.cplusplus.com/doc/tutorial/dynamic/ section "Operators new and new[]".
		// Initialize both currentGrid[x] and futureGrid[x] as arrays of bool objects with size depth.
		// This is where you will create the second dimension of your 2D array. Remember, these 
		// are arrays of bool, not bool*.
		//
		// YOUR CODE HERE

		// END YOUR CODE


		// TODO: Question #6 - What is the ternary operator and how does it work?
		// Read http://www.cplusplus.com/doc/tutorial/operators/ Section "Conditional ternary operator ( ? )"
		/**
		 * Initializes each boolean element in the array with a random value of ALIVE or DEAD
		 * using the rand() function and the ternary operator. Use the ternary operator in lieu
		 * of if-else statements.
		 **/
		for (int y = 0; y < depth; y++)
		{
			futureGrid[x][y] = currentGrid[x][y] = (rand() % 2 == 0) ? ALIVE : DEAD;
		}
	}

	/**
	 * Print out the initial grid
	 **/
	cout << "Initial Grid" << endl;
	printGrid(currentGrid);

	for (int i = 0; i < generations; i++)
	{
		/**
		 * Evolve the current grid and print out its evolution
		 **/
		evolve(currentGrid, futureGrid);
		cout << "After Evolution " << i << endl;
		printGrid(futureGrid);

		/**
		 * Update array pointers
		 **/
		// TODO: Question #7 -  Why is a temp pointer required? What happens if it is not used?
		bool** temp = currentGrid;
		currentGrid = futureGrid;
		futureGrid = temp;
	}

	/**
	 * Delete each array in the grid (i.e. delete each bool*)
	 **/
	// TODO: Question #8 - Why is delete[] required here? What is being deleted?
	// Read http://www.cplusplus.com/doc/tutorial/dynamic/ Section "Operators delete and delete[]"
	for (int x = 0; x < width; x++)
	{
		delete[] currentGrid[x];
		delete[] futureGrid[x];
	}

	// TODO: Task #2 - use the proper delete function to delete the memory pointed to by the 
	// currentGrid and futureGrid pointers
	// Read http://www.cplusplus.com/doc/tutorial/dynamic/ Section "Operators delete and delete[]"
	//
	// YOUR CODE HERE

	// END YOUR CODE

	return 0;
}





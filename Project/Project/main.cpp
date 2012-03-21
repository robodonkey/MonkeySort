#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

const int SIZE_OF_LIST = 7;
int numbers[SIZE_OF_LIST];
bool moved[SIZE_OF_LIST];

/*
 * This function looks over the moved array to make sure that all of the
 * values have been moved this iteration.
 */
bool allMoved()
{
	int countOfNotMoved = 0;
	for(int i = 0; i < SIZE_OF_LIST; i++)
	{
		if(moved[i] == false)
		{
			countOfNotMoved++;
		}
	}
	if(countOfNotMoved < 2)
		return true;
	return false;
}

/*
 * This function will pick 2 random locations that have not been moved yet,
 * and swap the contents of those two locations.
 */
void shuffle()
{
	int location = 0, counter = 0;
	int locations[2] = {0, 0};
	int temp = 0;
	
	//Find 2 locations that haven't been used before
	while(!allMoved() && counter < 2)
	{
		location = rand() % SIZE_OF_LIST;
		if(moved[location] != true)
		{
			moved[location] = true;
			locations[counter] = location;
			counter++;
		}
	}

	//Swap the locations
	temp = numbers[locations[0]];
	numbers[locations[0]] = numbers[locations[1]];
	numbers[locations[1]] = temp;
}

/*
 * This changes the state of all moved locations to false 
 */
void removeAllMoved()
{
	for(int index = 0; index < SIZE_OF_LIST; index++)
	{
		moved[index] = false;
	}

}

/*
 * This function iterates over the list, and checks of the current location is greater
 * than the next location. If so, the list is not sorted, and it returns false.
 */
bool isSorted()
{
	for(int index = 0; index < SIZE_OF_LIST - 1; index++)
	{
		if(numbers[index] > numbers[index + 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	srand((unsigned int)time(0));
	unsigned int counter = 0;

	//Create the list of random numbers
	for(int index = 0; index < SIZE_OF_LIST; index++)
	{
		numbers[index] = rand() % 1000;
		moved[index] = false;
		cout << numbers[index] << " ";
	}
	cout << endl;
	cout << "Working" << endl;

	//Shuffle the board while it isn't sorted
	while(!isSorted())
	{
		if(allMoved())
		{
			removeAllMoved();
		}
		shuffle();
		counter++;
	}
	cout << "done" << endl;

	//Output sorted list
	for(int index = 0; index < SIZE_OF_LIST; index++)
	{
		cout << numbers[index] << " ";
	}
	cout << endl;
	cout << "Iterations: " << counter << endl;
	system("pause");
	return 0;
}
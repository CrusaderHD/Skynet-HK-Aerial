//Creator Information:
/*
Name: Hunter Derrick
Professor: Tony Hinton
Part 1 Start: 10/16/18  -- Part 1 Finish: 10/20/2018
Project Name: Skynet HK-Aerial
*/
//Task:
/*
Write a program in C++ for the Skynet HK-Aerial
You should initialize a grid search of 8x8.
On each run, your program should choose a random numbered square on the grid numbered 1-64 to indicate where the enemy is located.
The enemy does not move in this simulation.
This program should be able to search for ground based enemies faster then when in the current linear search HK mode, however, you do not need to code in this comparison.
This program is for it's internal AI only and does not require human other other AI players.
This program should keep track of each turn and display this.
This program should use an unpredictable search pattern (the algorithm below) to the human on the ground.
The AI should used a Binary Search Pattern.
This program should loop until the Grid that the enemy is on is found by the Skynet HK-Aerial. At that point the found and engaging enemy status is displayed along with other information such as how long it took to find them by showing how many grids the HK searched before finding the enemy, what where the coordinates of the grids the HK looked at, and how large the search grid was.
This code will be upgraded often to stay ahead of the enemy. Be sure to comment each line of code except cout statements, write very readable code using good coding standards.
The Grid does not need to be displayed.
Put this project into your GitHub and take a screenshot of it.
*/

#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;


int main()
{
	srand(static_cast<unsigned int>(time(0)));  //Seed the Random Number Generator.

	int enemyLocation = rand() % 64 + 1; //Random number between 1 and 64.
	int gridMax = 64;
	int gridMin = 1;
	int predictions = 0;
	int guessLocation = rand() % 64 + 1; //Random number between 1 and 64.

	bool enemyFound = false;
	cout << "\n\t\t\t\t\t Welcome to Skynet, Captain.\n\n";
	cout << "Today, you will be witnessing our newest A.I UAV. The 'HK-Aerial'.\n\n";
	cout << "HK-Aerial Software Initalizing...\n\n";
	cout << "Captain, our Intelligence software stragetically places an enemy randomly within an 8x8 Grid.\nAllowing 1 of 64 random locations to be selected within the grid\n";
	cout << "HK-Aerial, automatically hunts down and tracks the enemy in the correct grid sector within a matter of seconds.\n\n";
	

	//Create the search loop (do) function.
	do
	{
		cout << "'HK-Aerial' Sending out Ping # " << predictions << "\n";
		

		if (guessLocation > enemyLocation)
		{
			cout << "\nThe enemy location is not in Grid # " << guessLocation << " number too high.\n";
			gridMax = guessLocation;
			guessLocation = ((gridMax - gridMin) / 2) + gridMin;
			predictions++;
		}
		else if (guessLocation < enemyLocation)
		{
			cout << "\nThe enemy location is not in Grid # " << guessLocation << " number too low.\n";
			gridMin = guessLocation;
			guessLocation = ((gridMax - gridMin) / 2) + gridMin;
			predictions++;
		}
		if(guessLocation == enemyLocation)
		{
			cout << "\nThe enemy was located in Grid #" << enemyLocation << "\n";
			cout << "\nEnemy Location Spotted. Only took 'HK-Aerial " << predictions << " search attempts.\n";
			enemyFound = true;
		}

	} while (enemyLocation != guessLocation);

	system("pause");
	return(0);
}
#include<iostream>
#include"GameWorld.h"
#include"Header.h"
#include"Automatic_Mode.h"
#include <cstdlib>
#include<conio.h>
#include<ctime>
#include<chrono>
using namespace std;
int main()
{
	//Score = 
	int timeElapsed=0, disCovered=0, numOfObstacles=0, numOfPowerup=0;
	
	//int score = (TimeFactor * timeElapsed) + (DistanceFactor * disCovered) - (ObstacleFactor * numObstacles) + (PowerUpFactor * NumPowerUps);
	int score = 0;
	auto startTime = chrono::steady_clock::now(); 
	srand(time(0));
	queue obstacles;
	queue powerup;
	
	/*int grid=5 + (rand() % 15);*/
	int grid = 5;
	// enqueuing obstacles
	for (int i = 0; i < grid; i++)
	{
		int randObstacle = rand() % 3;
		if (randObstacle==0)
		{
			int obstaclePower = 10 + (rand() % 10);
			char obstacle = '#';
			GameElement* ele=new GameElement(-1*obstaclePower, obstacle);
			obstacles.enqueue(ele);
		}
		else if (randObstacle == 1)
		{
			int obstaclePower = 10 + (rand() % 10);
			char obstacle = '|';
			GameElement* ele = new GameElement(-1*obstaclePower, obstacle);
			obstacles.enqueue(ele);
		}
		else
		{
			int obstaclePower = 10 + (rand() % 10);
			char obstacle = 'X';
			GameElement* ele = new GameElement(-1*obstaclePower, obstacle);
			obstacles.enqueue(ele);
		}
		
	}
	
	// enqueuing powerups
	for (int i = 0; i < grid; i++)
	{
		int randPowerup = rand() % 3;
		if (randPowerup == 0)
		{
			int power = 10 + (rand() % 10);
			char obstacle = '$';
			GameElement* ele=new GameElement(power, obstacle);
			powerup.enqueue(ele);
		}
		else if (randPowerup == 1)
		{
			int power = 10 + (rand() % 10);
			char obstacle = '!';
			GameElement* ele = new GameElement(power, obstacle);
			powerup.enqueue(ele);
		}
		else
		{
			int power = 10 + (rand() % 10);
			char obstacle = '\xE2';
			GameElement* ele = new GameElement(power, obstacle);
			powerup.enqueue(ele);
		}

	}
	
	//collecting powerups in linkedlist
	CollectionOfPowerUps collect;

	bool check = false;
	// Random values used for placing C and E
	int randomVal1 = rand() % grid;
	int randomVal2 = rand() % grid;
	LinkedList* graph = new LinkedList[grid];
	// I am here inserting values
	for (int i = 0; i < grid; i++)
	{
		int indexOfObstcle = rand() % grid;
		int indexOfPowerup = rand() % grid;
		for (int j = 0; j < grid; j++)
		{

			if (j == indexOfObstcle)
			{
				graph[i].insert(obstacles.Front());
				obstacles.dequeue();
			}
			else if (j == indexOfPowerup)
			{
				graph[i].insert(powerup.Front());
				powerup.dequeue();
			}
			else if (i == 0 && j == randomVal1)
			{
				int randPos = rand() % 2;
				if (randPos == 1)
				{
					GameElement* element = new GameElement(0, 'C');
					graph[i].insert(element);
				}
				else
				{
					GameElement* element = new GameElement(0, 'E');
					graph[i].insert(element);
					check = true;
				}
			}
			else if (i == grid - 1 && j == randomVal2)
			{
				if (check)
				{
					GameElement* element = new GameElement(0, 'C');
					graph[i].insert(element);
				}
				else
				{
					GameElement* element = new GameElement(0, 'E');
					graph[i].insert(element);
				}
				
			}
			else
			{
				GameElement* element = new GameElement(0, '*');
				graph[i].insert(element);
			}
			
		}
	}
	insertingNodesInGraph(graph, grid);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "TIMER : 0 seconds" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	displayGraph(graph, grid);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << "SCORE : " << score << endl;
	cout << "DISTANCE COVERED : " << disCovered << endl;
	cout << "NO OF OBSTACLES HIT : "<<numOfObstacles << endl;
	cout << "COLLECTED POWER-UPS : ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	collect.display();
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	int ch;
	while (1)
	{
		cout << "Press w to move" << endl;
		cout << "Press d to turn right" << endl;
		cout << "Press a to turn left" << endl;
		cout << "Press s to turn back" << endl;
		 ch = _getch();
		 system("cls");
		if (ch == 'w')
		{
			// calculating distance for each click
			disCovered++;
			auto currentTime = chrono::steady_clock::now();
			auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
			if (move(graph, 'C', grid, collect, numOfObstacles))
			{
				cout << "Game ended Susscessfully" << endl;
				break;
			}
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "TIMER : " << elapsedTime.count() << " seconds" << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			displayGraph(graph, grid);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "SCORE : " << score << endl;
			cout << "DISTANCE COVERED : " << disCovered << endl;
			cout << "NO OF OBSTACLES HIT : " << numOfObstacles << endl;
			cout << "COLLECTED POWER-UPS : ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
			collect.display();
			cout << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
		else if (ch == 'd')
		{
			// calculating distance for each click
			disCovered++;
			auto currentTime = chrono::steady_clock::now();
			auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
			if (turnRight(graph, 'C', grid, collect, numOfObstacles))
			{
				cout << "Game ended Susscessfully" << endl;
				break;
			}
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "TIMER : " << elapsedTime.count() << " seconds" << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			displayGraph(graph, grid);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "SCORE : " << score << endl;
			cout << "DISTANCE COVERED : " << disCovered << endl;
			cout << "NO OF OBSTACLES HIT : " << numOfObstacles << endl;
			cout << "COLLECTED POWER-UPS : ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
			collect.display();
			cout << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
		else if (ch == 'a')
		{
			// calculating distance for each click
			disCovered++;
			auto currentTime = chrono::steady_clock::now();
			auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
			if (turnLeft(graph, 'C', grid, collect, numOfObstacles))
			{
				cout << "Game ended Susscessfully" << endl;
				break;
			}
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "TIMER : " << elapsedTime.count() << " seconds" << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			displayGraph(graph, grid);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "SCORE : " << score << endl;
			cout << "DISTANCE COVERED : " << disCovered << endl;
			cout << "NO OF OBSTACLES HIT : " << numOfObstacles << endl;
			cout << "COLLECTED POWER-UPS : ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
			collect.display();
			cout << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
		else if (ch == 's')
		{
			// calculating distance for each click
			disCovered++;
			auto currentTime = chrono::steady_clock::now();
			auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
			if (back(graph, 'C', grid, collect, numOfObstacles))
			{
				cout << "Game ended Susscessfully" << endl;
				break;
			}
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "TIMER : " << elapsedTime.count() << " seconds" << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			displayGraph(graph, grid);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << "SCORE : " << score << endl;
			cout << "DISTANCE COVERED : " << disCovered << endl;
			cout << "NO OF OBSTACLES HIT : " << numOfObstacles << endl;
			cout << "COLLECTED POWER-UPS : ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
			collect.display();
			cout << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		}
		else 
		{
			break;
		}
	}
	/*int noOfAdjV;
	for (int i = 0; i < vertix; i++)
	{
		cout << "Enter no of adjacent vertices of vertix " << i + 1 << " : ";
		cin >> noOfAdjV;
		for (int j = 0; j < noOfAdjV; j++)
		{
			int data;
			cout << "Enter " << j + 1 << " adjacent vertices of vertix " << i + 1 << " : ";
			cin >> data;
			graph[i].insert(data);
		}
	}*/
	return 0;
}
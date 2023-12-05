#pragma once
#include<iostream>
#include"AutomaticMode.h"
#include"LeaderBoard.h"
#include"RandomText.h"
using namespace std;
void newGame(Queue& obstacles, LinkedList*& graph, Queue& powerup, CollectionOfPowerUps& collect, int& grid, int& obstaclePowerHash, int& obstaclePowerBar, int& obstaclePowerX)
{
	srand(time(0));
	grid = 5 + (rand() % 15);
	// enqueuing obstacles
	// small obstacle medium obstacle | large obstacle | X
	obstaclePowerHash = 20 + (rand() % 10);
	obstaclePowerBar = 15 + (rand() % 10);
	obstaclePowerX = 10 + (rand() % 10);
	for (int i = 0; i < grid; i++)
	{
		int randObstacle = rand() % 3;
		if (randObstacle == 0)
		{

			char obstacle = '#';
			GameElement* ele = new GameElement(-1 * obstaclePowerHash, obstacle);
			obstacles.enqueue(ele);
		}
		else if (randObstacle == 1)
		{

			char obstacle = '|';
			GameElement* ele = new GameElement(-1 * obstaclePowerHash, obstacle);
			obstacles.enqueue(ele);
		}
		else
		{

			char obstacle = 'X';
			GameElement* ele = new GameElement(-1 * obstaclePowerHash, obstacle);
			obstacles.enqueue(ele);
		}

	}

	// enqueuing powerups
	// max power \xe2 medium power ! low power $
	for (int i = 0; i < grid; i++)
	{
		int randPowerup = rand() % 3;
		if (randPowerup == 0)
		{
			int power = 10 + (rand() % 10);
			char obstacle = '$';
			GameElement* ele = new GameElement(power, obstacle);
			powerup.enqueue(ele);
		}
		else if (randPowerup == 1)
		{
			int power = 15 + (rand() % 10);
			char obstacle = '!';
			GameElement* ele = new GameElement(power, obstacle);
			powerup.enqueue(ele);
		}
		else
		{
			int power = 20 + (rand() % 10);
			char obstacle = '\xE2';
			GameElement* ele = new GameElement(power, obstacle);
			powerup.enqueue(ele);
		}

	}

	//collecting powerups in linkedlist
	bool check = false;
	// Random values used for placing C and E
	int randomVal1 = rand() % grid;
	int randomVal2 = rand() % grid;
	graph = new LinkedList[grid];
	// I am here inserting values
	for (int i = 0; i < grid; i++)
	{
		int indexOfObstcle = rand() % grid;
		int indexOfPowerup = rand() % grid;
		for (int j = 0; j < grid; j++)
		{

			if (i == 0 && j == randomVal1)
			{

				GameElement* element = new GameElement(0, 'E');
				graph[i].insert(element);
				check = true;
				continue;

			}
			if (i == grid - 1 && j == randomVal2)
			{
				GameElement* element = new GameElement(0, 'C');
				graph[i].insert(element);
				continue;

			}
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
			else
			{
				GameElement* element = new GameElement(2, '*');
				graph[i].insert(element);
			}

		}
	}

}
bool pressW(bool zeroForManual, int& grid, int& score, LinkedList*& graph, int& disCovered, CollectionOfPowerUps& collect, int& hash, int& bar, int& X, int& obstaclePowerHash, int& obstaclePowerBar, int& obstaclePowerX, int currentTime, int& storeShortestDistance)
{
	vector<int> vec;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	disCovered++;
	char whatHit;
	if (move(graph, 'C', grid, collect, hash, bar, X, whatHit))
	{
		cout << "Game ended Susscessfully" << endl;
		return 1;
	}
	// Counting scores here
	
	countScore(score,whatHit, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, currentTime, collect);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	if (zeroForManual)
	{
		vec = insertingNodesInGraph(graph, grid);
		storeShortestDistance = vec.size();
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	RandomInstruction();
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << setw(40) << "TIMER : " << currentTime << " seconds" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	if (zeroForManual)
	{
		displayGraph(vec, graph, grid);
	}
	else
	{
		displayGraph(graph, grid);
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << setw(50) << "SCORE : " << score << endl;
	cout << setw(50) << "DISTANCE COVERED : " << disCovered << endl;
	cout << setw(50) << "NO OF OBSTACLES HIT : " << bar + hash + X << endl;
	cout << setw(50) << "COLLECTED POWER-UPS : ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	collect.display();
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	return 0;

}
bool pressA(bool zeroForManual, int& grid, int& score, LinkedList*& graph, int& disCovered, CollectionOfPowerUps& collect, int& hash, int& bar, int& X, int& obstaclePowerHash, int& obstaclePowerBar, int& obstaclePowerX, int currentTime, int& storeShortestDistance)
{
	vector<int> vec;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	disCovered++;
	char whatHit;
	if (turnLeft(graph, 'C', grid, collect, hash, bar, X, whatHit))
	{
		cout << "Game ended Susscessfully" << endl;
		return 1;
	}
	// Counting scores here
	countScore(score, whatHit, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, currentTime, collect);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	if (zeroForManual)
	{
		vec = insertingNodesInGraph(graph, grid);
		storeShortestDistance = vec.size();
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	RandomInstruction();
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << setw(40) << "TIMER : " << currentTime << " seconds" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	if (zeroForManual)
	{
		displayGraph(vec, graph, grid);
	}
	else
	{
		displayGraph(graph, grid);
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << setw(50) << "SCORE : " << score << endl;
	cout << setw(50) << "DISTANCE COVERED : " << disCovered << endl;
	cout << setw(50) << "NO OF OBSTACLES HIT : " << bar + hash + X << endl;
	cout << setw(50) << "COLLECTED POWER-UPS : ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	collect.display();
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	return 0;
}
bool pressS(bool zeroForManual, int& grid, int& score, LinkedList*& graph, int& disCovered, CollectionOfPowerUps& collect, int& hash, int& bar, int& X, int& obstaclePowerHash, int& obstaclePowerBar, int& obstaclePowerX, int currentTime, int& storeShortestDistance)
{
	vector<int>vec;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	disCovered++;
	char whatHit;
	if (back(graph, 'C', grid, collect, hash, bar, X, whatHit))
	{
		cout << "Game ended Susscessfully" << endl;
		return 1;
	}
	// Counting scores here
	countScore(score, whatHit, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, currentTime, collect);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	if (zeroForManual)
	{
		vec = insertingNodesInGraph(graph, grid);
		storeShortestDistance = vec.size();
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	RandomInstruction();
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << setw(40) << "TIMER : " << currentTime << " seconds" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	if (zeroForManual)
	{
		displayGraph(vec, graph, grid);
	}
	else
	{
		displayGraph(graph, grid);
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << setw(50) << "SCORE : " << score << endl;
	cout << setw(50) << "DISTANCE COVERED : " << disCovered << endl;
	cout << setw(50) << "NO OF OBSTACLES HIT : " << bar + hash + X << endl;
	cout << setw(50) << "COLLECTED POWER-UPS : ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	collect.display();
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	return 0;
}
bool pressD(bool zeroForManual, int& grid, int& score, LinkedList*& graph, int& disCovered, CollectionOfPowerUps& collect, int& hash, int& bar, int& X, int& obstaclePowerHash, int& obstaclePowerBar, int& obstaclePowerX, int currentTime, int& storeShortestDistance)
{
	vector<int> vec;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	disCovered++;
	char whatHit;
	if (turnRight(graph, 'C', grid, collect, hash, bar, X, whatHit))
	{
		cout << "Game ended Susscessfully" << endl;
		return 1;
	}
	// Counting scores here
	countScore(score, whatHit, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, currentTime, collect);
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	if (zeroForManual)
	{
		vec = insertingNodesInGraph(graph, grid);
		storeShortestDistance = vec.size();
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	RandomInstruction();
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << setw(40) << "TIMER : " << currentTime << " seconds" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	if (zeroForManual)
	{
		displayGraph(vec, graph, grid);
	}
	else
	{
		displayGraph(graph, grid);
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
	cout << setw(50) << "SCORE : " << score << endl;
	cout << setw(50) << "DISTANCE COVERED : " << disCovered << endl;
	cout << setw(50) << "NO OF OBSTACLES HIT : " << bar + hash + X << endl;
	cout << setw(50) << "COLLECTED POWER-UPS : ";
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
	collect.display();
	cout << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	return 0;
}
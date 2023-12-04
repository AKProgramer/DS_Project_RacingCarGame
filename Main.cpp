#include<iostream>
#include"GameWorld.h"
#include"GameElement.h"
#include"AutomaticMode.h"
#include"MovementFunctions.h"
#include <cstdlib>
#include<iomanip>
#include<conio.h>
#include<ctime>
#include<chrono>
using namespace std;
int main()
{
	//Score = 
	int timeElapsed=0, disCovered=0, hash=0, bar=0, X=0, numOfPowerup=0;
	int storeShortestDistance = 0;
	//int score = (TimeFactor * timeElapsed) + (DistanceFactor * disCovered) - (ObstacleFactor * numObstacles) + (PowerUpFactor * NumPowerUps);
	int score = 0;
	auto startTime = chrono::steady_clock::now(); 
	srand(time(0));
	Queue obstacles;
	Queue powerup;
	LinkedList* graph;
	CollectionOfPowerUps collect;
	int grid = 0;
	int obstaclePowerHash =0;
	int obstaclePowerBar = 0;
	int obstaclePowerX = 0;
	newGame(obstacles, graph, powerup, collect, grid, obstaclePowerHash, obstaclePowerBar, obstaclePowerX);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int choice;
	int choice2;
	while (1)
	{
		cout << "1 for Manual" << endl;
		cout << "2 for Automatic" << endl;
		cout << "3 to exit" << endl;
		cin >> choice;
		system("cls");
		if (choice == 1)
		{
			while (1)
			{
				cout << "1 for new game" << endl;
				cout << "2 for resume" << endl;
				cin >> choice2;
				system("cls");
				if (choice2 == 1)
				{
					X = 0;
					bar = 0;
					hash = 0;
					disCovered = 0;
					collect.deleteCollectionOfPowerup();
					
					score = 0;
					newGame(obstacles, graph, powerup, collect, grid, obstaclePowerHash, obstaclePowerBar, obstaclePowerX);
					break;
				}
				else if (choice2 == 2)
				{
					break;
				}

			}
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << setw(40) << "TIMER : 0 seconds" << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			displayGraph(graph, grid);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << setw(50) << "SCORE : " << score << endl;
			cout << setw(50) << "DISTANCE COVERED : " << disCovered << endl;
			cout << setw(50) << "NO OF OBSTACLES HIT : " << bar + hash + X << endl;
			cout << setw(50) << "COLLECTED POWER-UPS : ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
			collect.display();
			cout << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			int ch;
			while (1)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
				cout << setw(83) << "Press w to move forword" << endl;
				cout << setw(81) << "Press d to turn right" << endl;
				cout << setw(80) << "Press a to turn left" << endl;
				cout << setw(80) << "Press s to turn back" << endl;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
				ch = _getch();
				system("cls");

				if (ch == 'w')
				{

					auto currentTime = chrono::steady_clock::now();
					auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
					if(pressW(0, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
					{
						break;
					}

				}
				else if (ch == 'd')
				{
					auto currentTime = chrono::steady_clock::now();
					auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
					if (pressD(0, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
					{
						break;
					}

				}
				else if (ch == 'a')
				{
					auto currentTime = chrono::steady_clock::now();
					auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
					if (pressA(0, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
					{
						break;
					}
				}
				else if (ch == 's')
				{
					auto currentTime = chrono::steady_clock::now();
					auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
					if (pressS(0, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
					{
						break;
					}

				}
				else
				{
					break;
				}
			}
		}
			
		else if (choice == 2)
		{
			int choice3;
			while (1)
			{
				cout << "1 for new game" << endl;
				cout << "2 for resume" << endl;
				cin >> choice3;
				system("cls");
				if (choice3 == 1)
				{
					X = 0;
					bar = 0;
					hash = 0;
					disCovered = 0;
					collect.deleteCollectionOfPowerup();
					newGame(obstacles, graph, powerup, collect, grid, obstaclePowerHash, obstaclePowerBar, obstaclePowerX);
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					insertingNodesInGraph(graph, grid);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
				
					break;
				}
				else if (choice3 == 2)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					insertingNodesInGraph(graph, grid);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
					break;
				}

			}
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << setw(40) << "TIMER : 0 seconds" << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			displayGraph(graph, grid);
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
			cout << setw(50) << "SCORE : " << score << endl;
			cout << setw(50) << "DISTANCE COVERED : " << disCovered << endl;
			cout << setw(50) << "NO OF OBSTACLES HIT : " << bar + hash + X << endl;
			cout << setw(50) << "COLLECTED POWER-UPS : ";
			SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_RED);
			collect.display();
			cout << endl;
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			int ch;
			while (1)
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
				cout << setw(83) << "Press w to move forword" << endl;
				cout << setw(81) << "Press d to turn right" << endl;
				cout << setw(80) << "Press a to turn left" << endl;
				cout << setw(80) << "Press s to turn back" << endl;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
				ch = _getch();
				system("cls");

				if (ch == 'w')
				{

					auto currentTime = chrono::steady_clock::now();
					auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
					if(pressW(1, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
					{
						break;
					}

				}
				else if (ch == 'd')
				{
					auto currentTime = chrono::steady_clock::now();
					auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
					if (pressD(1, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
					{
						break;
					}

				}
				else if (ch == 'a')
				{
					auto currentTime = chrono::steady_clock::now();
					auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
					if (pressA(1, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
					{
						break;
					}
				}
				else if (ch == 's')
				{
					auto currentTime = chrono::steady_clock::now();
					auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
					if (pressS(1, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
					{
						break;
					}

				}
				else
				{
					break;
				}
			}
		}
	}
	
	return 0;
}
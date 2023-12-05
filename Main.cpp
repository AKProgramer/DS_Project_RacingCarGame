#include<iostream>
#include"GameWorld.h"
#include"GameElement.h"
#include"AutomaticMode.h"
#include"MovementFunctions.h"
#include"RandomText.h"
#include <cstdlib>
#include<iomanip>
#include<conio.h>
#include<ctime>
#include<chrono>
#include"Menu.h"

using namespace std;
int main()
{
	//Score = 
	int timeElapsed=0, disCovered=0, hash=0, bar=0, X=0, numOfPowerup=0;
	int storeShortestDistance = 0;
	string username;
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
	int choiceInScreen3;
	cout << "Enter your name : ";
	cin >> username;
	int choiceInScreen1 = 0;
	while (1)
	{
		system("cls");
		screen1();
		cin >> choiceInScreen1;
		if (choiceInScreen1 == 1)
		{
			system("cls");
			bool checkVisibilityOfResume = false;
			bool autoNewGame = false;
		while (1)
		{
			screen2();
			cin >> choice;
			system("cls");
			
			if (choice == 1)
			{
				while (1)
				{
					if (checkVisibilityOfResume)
					{
						system("cls");
						newGame();
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
					else
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
				}
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				RandomInstruction();
				cout << endl;
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
						if (pressW(0, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
						{
							createFileAndStoreScore(username, score);
							checkVisibilityOfResume = true;
							break;
						}

					}
					else if (ch == 'd')
					{
						auto currentTime = chrono::steady_clock::now();
						auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
						if (pressD(0, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
						{
							createFileAndStoreScore(username, score);
							checkVisibilityOfResume = true;
							break;
						}

					}
					else if (ch == 'a')
					{
						auto currentTime = chrono::steady_clock::now();
						auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
						if (pressA(0, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
						{
							createFileAndStoreScore(username, score);
							checkVisibilityOfResume = true;
							break;
						}
					}
					else if (ch == 's')
					{
						auto currentTime = chrono::steady_clock::now();
						auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
						if (pressS(0, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
						{
							createFileAndStoreScore(username, score);
							checkVisibilityOfResume = true;
							break;
						}

					}
					else
					{
						checkVisibilityOfResume = true;
						break;
					}
				}
			}

			else if (choice == 2)
			{
				vector<int> vec;
				auto currentTime = chrono::steady_clock::now();
				auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
				int storeCurrentTime = elapsedTime.count();
				int choice3;
				if (autoNewGame)
				{
					while (1)
					{
						newGame();
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
							vec = insertingNodesInGraph(graph, grid);
							SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

							break;
						}
						else if (choice3 == 2)
						{

							SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
							vec = insertingNodesInGraph(graph, grid);
							SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
							break;
						}

					}
				}
				else
				{
					X = 0;
					bar = 0;
					hash = 0;
					disCovered = 0;
					collect.deleteCollectionOfPowerup();
					newGame(obstacles, graph, powerup, collect, grid, obstaclePowerHash, obstaclePowerBar, obstaclePowerX);
					SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
					vec = insertingNodesInGraph(graph, grid);
					SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
				}
				
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				RandomInstruction();
				cout << endl;
				cout << setw(40) << "TIMER : 0 seconds" << endl;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
				displayGraph(vec, graph, grid);
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

						auto currentTime1 = chrono::steady_clock::now();
						auto elapsedTime1 = chrono::duration_cast<chrono::seconds>(currentTime1 - startTime);
						if (pressW(1, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime1.count() - storeCurrentTime, storeShortestDistance))
						{
							autoNewGame = true;
							break;
						}

					}
					else if (ch == 'd')
					{
						auto currentTime = chrono::steady_clock::now();
						auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
						if (pressD(1, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
						{
							autoNewGame = true;
							break;
						}

					}
					else if (ch == 'a')
					{
						auto currentTime = chrono::steady_clock::now();
						auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
						if (pressA(1, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
						{
							autoNewGame = true;
							break;
						}
					}
					else if (ch == 's')
					{
						auto currentTime = chrono::steady_clock::now();
						auto elapsedTime = chrono::duration_cast<chrono::seconds>(currentTime - startTime);
						if (pressS(1, grid, score, graph, disCovered, collect, hash, bar, X, obstaclePowerHash, obstaclePowerBar, obstaclePowerX, elapsedTime.count(), storeShortestDistance))
						{
							autoNewGame = true;
							break;
						}

					}
					else
					{
						autoNewGame = true;
						break;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
		else if (choiceInScreen1 == 2)
		{
			system("cls");
			screen3();
			cin >> choiceInScreen1;
			if (choiceInScreen1 == 2)
			{
				system("cls");
				int n;
				cout << "Press any thing to go back" << endl;
				LeaderBoard* lb = new LeaderBoard;
				cout << setw(35) << "LEADERBOARD\n";
				cout <<setw(100)<< "--------------------------------------------------------" << endl;
				cout << "|" << setw(10) << "Rank" << setw(20) << "Name" << setw(20) << "Score" << setw(5) << "|" << endl;
				cout <<setw(100)<< "--------------------------------------------------------" << endl;
				lb->printScores(lb->getHead());
				cout <<setw(100)<< "--------------------------------------------------------" << endl;
				n = _getch();

			}
			
		}
		else
		{
			break;
		}
	}
	
	
	return 0;
}
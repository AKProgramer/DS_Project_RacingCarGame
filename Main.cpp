#include<iostream>
#include"GameWorld.h"
#include"Header.h"
#include <cstdlib>
#include<conio.h>
#include<ctime>
using namespace std;
int main()
{
	srand(time(0));
	queue obstacles;
	queue powerup;
	int grid=5 + (rand() % 15);
	// enqueuing obstacles
	for (int i = 0; i < grid; i++)
	{
		obstacles.enqueue('#');
	}
	
	bool check = false;
	int randomVal1 = rand() % grid;
	int randomVal2 = rand() % grid;
	LinkedList* graph = new LinkedList[grid];
	for (int i = 0; i < grid; i++)
	{
		int indexOfObstcle = rand() % grid;
		int indexOfPowerup = rand() % grid;
		for (int j = 0; j < grid; j++)
		{

			char ch = '*';
			if (j == indexOfObstcle)
			{
				ch = obstacles.Front();
				obstacles.dequeue();
			}
			if (j == indexOfPowerup)
			{
				ch = '\xE2';
			}
			if (i == 0 && j == randomVal1)
			{
				int randPos = rand() % 2;
				if (randPos == 1)
				{
					char ch = 'C';
					graph[i].insert(ch);
				}
				else
				{
					char ch = 'E';
					graph[i].insert(ch);
					check = true;
				}
			}
			else if (i == grid - 1 && j == randomVal2)
			{
				if (check)
				{
					char ch = 'C';
					graph[i].insert(ch);
				}
				else
				{
					char ch = 'E';
					graph[i].insert(ch);
				}
				
			}
			else
			{
				
				graph[i].insert(ch);
			}
			
		}
	}
	displayGraph(graph, grid);
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
			
			if (move(graph, 'C', grid))
			{
				cout << "Game ended Susscessfully" << endl;
				break;
			}
			displayGraph(graph, grid);
		}
		else if (ch == 'd')
		{
			if (turnRight(graph, 'C', grid))
			{
				cout << "Game ended Susscessfully" << endl;
				break;
			}
			displayGraph(graph, grid);
		}
		else if (ch == 'a')
		{
			turnLeft(graph, 'C', grid);
			displayGraph(graph, grid);
		}
		else if (ch == 's')
		{
			if (back(graph, 'C', grid))
			{
				cout << "Game ended Susscessfully" << endl;
				break;
			}
			displayGraph(graph, grid);
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
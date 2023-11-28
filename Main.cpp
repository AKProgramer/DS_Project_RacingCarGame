#include<iostream>
#include"GameWorld.h"
#include<ctime>
#include<queue>
#include<vector>
using namespace std;

int main()
{
	
	
	srand(time(0));
	
	int grid=5 + (rand() % 15);
	int noOfObstacles = grid;
	
	cout << "Enter No Of Vertices" << endl;
	LinkedList* graph = new LinkedList[grid];
	for (int i = 0; i < grid; i++)
	{
		int indexOfObstcle = rand() % grid;
		for (int j = 0; j < grid; j++)
		{

			char ch = '*';
			if (j == indexOfObstcle)
			{
				ch = '|';
			}
			if (i == 0 && j == 0)
			{
				char ch = 'C';
				graph[i].insert(ch);
			}
			else if (i == grid - 1 && j == grid - 1)
			{
				char ch = 'E';
				graph[i].insert(ch);
			}
			else
			{
				
				graph[i].insert(ch);
			}
			
		}
	}
	displayGraph(graph, grid);
	while (1)
	{
		char ch;
		cout << "Press w to move" << endl;
		cout << "Press d to turnRight" << endl;
		cin >> ch;
		if (ch == 'w')
		{
			move(graph, 'C', grid);
			displayGraph(graph, grid);
		}
		else if (ch == 'd')
		{
			moveRight(graph, 'C', grid);
			displayGraph(graph, grid);
		}
		else if (ch == 'a')
		{
			moveLeft(graph, 'C', grid);
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
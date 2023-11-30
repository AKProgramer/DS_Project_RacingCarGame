#pragma once
#include<iostream>
#include<Windows.h>
using namespace std;
struct Node {
	char data;
	int weight = 0;
	Node* next;
	Node()
	{
		data = -1;
		next = NULL;
		weight = 0;
	}
	Node(char d)
	{
		weight = 0;
		data = d;
		next = NULL;
	}
};
class LinkedList
{
	Node* list;
public:
	LinkedList()
	{
		list = NULL;
	}
	Node* getlist()
	{
		return list;
	}
	void insert(char d)
	{
		if (list == NULL)
		{
			list = new Node(d);
			return;
		}
		Node* traverse = list;
		while (traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		traverse->next = new Node(d);
		
	}
	
	void display()
	{
		Node* temp = list;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "| ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		while (temp != NULL)
		{
			if (temp->data == '#')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				cout << temp->data << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else if (temp->data == '\xE2')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
				cout << temp->data << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else if (temp->data == 'C')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				cout << temp->data << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else if (temp->data == 'E')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				cout << temp->data << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			
			else
			{
				//cout << temp->data << " ";
				cout << "  ";
				temp = temp->next;
			}
			
		}
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << '|';
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	}
	
};
//d right
bool turnRight(LinkedList*& graph, char ch, int size)
{
	for (int i = 0; i < size; i++)
	{
		Node* traverse = graph[i].getlist();

		while (traverse != NULL)
		{
			
			if (traverse->data == ch)
			{
				//&& traverse->next->data != '|'
				if (traverse->next != NULL)
				{
					if (traverse->next->data == 'E')
					{
						return 1;
					}
					char store = traverse->next->data;
					traverse->next->data = traverse->data;
					traverse->data = store;
					traverse = traverse->next;
				}
			}
			traverse = traverse->next;
		}
		
	}
	return 0;
}
//s back
bool back(LinkedList*& graph, char ch, int size)
{
	for (int i = 0; i < size-1; i++)
	{
		bool check = false;
		Node* traverse = graph[i].getlist();
		Node* right = graph[i + 1].getlist();
		while (traverse != NULL)
		{
			if (traverse->data == ch)
			{
				//if (right->data != '|')
				//{
					if (right->data == 'E')
					{
						return 1;
					}
					char store = right->data;
					right->data = traverse->data;
					traverse->data = store;
					check = true;
				//}
				
			}
			right = right->next;
			traverse = traverse->next;
		}
		if (check == true)
		{
			break;
		}
		
	}
	return 0;
}
// w move
bool move(LinkedList*& graph, char ch, int size)
{
	for (int i = 1; i < size; i++)
	{
		Node* traverse = graph[i].getlist();
		Node* left = graph[i - 1].getlist();
		while (traverse != NULL)
		{
			if (traverse->data == ch)
			{
				//if (left->data != '|')
				//{
					if (traverse->next->data == 'E')
					{
						return 1;
					}
					char store = left->data;
					left->data = traverse->data;
					traverse->data = store;
					
				//}

			}
			left = left->next;
			traverse = traverse->next;
		}

	}
	return 0;
}
// leftturn
void turnLeft(LinkedList*& graph, char ch, int size)
{
	for (int i = 0; i < size; i++)
	{
		Node* traverse = graph[i].getlist();
		while (traverse->next != NULL)
		{
			if (traverse->next->data == ch)
			{
				//if (traverse->data != '|')
				//{
					char store = traverse->next->data;
					traverse->next->data = traverse->data;
					traverse->data = store;
				//}

			}
			traverse = traverse->next;
		}
	}
}
void displayGraph(LinkedList* arr, int size)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	for (int i = 0; i < (size* 2)+3; i++)
	{
		cout << "-";
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i].display();
		cout << endl;
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
	for (int i = 0; i < (size*2)+3; i++)
	{
		cout << "-";
	}
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << endl;
}


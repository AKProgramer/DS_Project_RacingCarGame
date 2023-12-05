#pragma once
#include<iostream>
#include"GameElement.h"
#include<Windows.h>
#include<iomanip>
#include<vector>
using namespace std;
struct Node {
	GameElement* element;
	Node* next;
	Node()
	{
		element=NULL;
		next = NULL;
	}
	Node(GameElement* d)
	{
		element = d;
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
	void insert(GameElement* element)
	{
		if (element == NULL)
		{
			return;
		}
		Node* newNode = new Node(element);
		if (list == NULL)
		{
			list = newNode;
			return;
		}
		Node* traverse = list;
		while (traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		traverse->next =newNode;
		
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
			if (temp->element->character == '#' || temp->element->character == '|' || temp->element->character == 'X')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				cout <<temp->element->character << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else if (temp->element->character == '.' || temp->element->character == 'T')
			{
				cout << temp->element->character << " ";
				temp = temp->next;
			}
			else if (temp->element->character == '\xE2' || temp->element->character == '$' || temp->element->character == '!')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
				cout << temp->element->character << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else if (temp->element->character == 'C')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				cout << temp->element->character << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else if (temp->element->character == 'E')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				cout << temp->element->character << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			
			else
			{
				cout << temp->element->character << " ";
				temp = temp->next;
			}
			
		}
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << '|';
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	}
	void display(vector<int> vec)
	{
		Node* temp = list;
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << "| ";
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
		while (temp != NULL)
		{
			bool check = false;
			if (temp->element->character == '#' || temp->element->character == '|' || temp->element->character == 'X')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
				for (int i = 1; i < vec.size()-1; i++)
				{
					if (temp->element->id == vec[i])
					{
						check = true;
					}
				}
				if (check)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
				}
				cout <<temp->element->character << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else if (temp->element->character == '\xE2' || temp->element->character == '$' || temp->element->character == '!')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
				for (int i = 1; i < vec.size() - 1; i++)
				{
					if (temp->element->id == vec[i])
					{
						check = true;
					}
				}
				if (check)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
				}
				cout << temp->element->character << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else if (temp->element->character == 'C')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				cout << temp->element->character << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			else if (temp->element->character == 'E')
			{
				SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
				cout << temp->element->character << " ";
				temp = temp->next;
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			}
			
			else
			{
				for (int i = 1; i < vec.size() - 1; i++)
				{
					if (temp->element->id == vec[i])
					{
						check = true;
					}
				}
				if (check)
				{
					SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
				}
				cout << temp->element->character << " ";
				SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
				temp = temp->next;
			}
		}
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
		cout << '|';
		SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	}
	
};
//d right
bool turnRight(LinkedList*& graph, char ch, int size, CollectionOfPowerUps& collection, int& hash, int& bar, int& X, char& what)
{
	for (int i = 0; i < size; i++)
	{
		Node* traverse = graph[i].getlist();

		while (traverse != NULL)
		{
			
			if (traverse->element->character == ch)
			{
				//&& traverse->next->element->character != '|'
				if (traverse->next != NULL)
				{
					if (traverse->next->element->character == '#')
					{
						hash++;
						what = '#';
					}
					else if (traverse->next->element->character == '|')
					{
						bar++;
						what = '|';
					}
					else if (traverse->next->element->character == 'X')
					{
						X++;
						what = 'X';
					}
					else if (traverse->next->element->character == '*')
					{
						what = '*';
					}
					else if (traverse->next->element->character == '\xE2' || traverse->next->element->character == '$' || traverse->next->element->character == '!')
					{
						if (traverse->next->element->character == '\xE2')
						{
							what = '\xE2';
						}
						else if (traverse->next->element->character == '$')
						{
							what = '$';
						}
						else
						{
							what = '!';
						}
						GameElement* temp = new GameElement(traverse->next->element->power, traverse->next->element->character);
						
						cout << traverse->next->element->character << endl;
						collection.insert(temp);
						traverse->next->element->character = '*';
					}
					else if (traverse->next->element->character == 'E')
					{
						return 1;
					}
						char store = traverse->next->element->character;
						traverse->next->element->character = traverse->element->character;
							traverse->element->character = store;
						
						traverse = traverse->next;
				}
			}
			traverse = traverse->next;
		}
		
	}
	return 0;
}
//s back
bool back(LinkedList*& graph, char ch, int size, CollectionOfPowerUps& collection, int& hash, int& bar, int& X, char& what)
{
	for (int i = 0; i < size-1; i++)
	{
		bool check = false;
		Node* traverse = graph[i].getlist();
		Node* lower = graph[i + 1].getlist();
		while (traverse != NULL)
		{
			if (traverse->element->character == ch)
			{

				//if (right->element->character != '|')
				//{
				if (lower->element->character == '#')
				{
					hash++;
					what = '#';
				}
				else if (lower->element->character == '|')
				{
					bar++;
					what = '|';
				}
				else if (lower->element->character == 'X')
				{
					X++;
					what = 'X';
				}
				else if (lower->element->character == '*')
				{
					what = '*';
				}
				else if (lower->element->character == '\xE2' || lower->element->character == '$' || lower->element->character == '!')
				{
					if (lower->element->character == '\xE2')
					{
						what = '\xE2';
					}
					else if (lower->element->character == '$')
					{
						what = '$';
					}
					else
					{
						what = '!';
					}
					GameElement* temp = new GameElement(lower->element->power, lower->element->character);
					collection.insert(temp);
					lower->element->character = '*';
				}
				else if (lower->element->character == 'E')
				{
					return 1;
				}
					char store = lower->element->character;
					lower->element->character = traverse->element->character;
					traverse->element->character = store;
					check = true;
				//}
				
			}
			lower = lower->next;
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
bool move(LinkedList*& graph, char ch, int size, CollectionOfPowerUps& collection,int& hash, int& bar, int& X, char& what)
{
	for (int i = 1; i < size; i++)
	{
		Node* traverse = graph[i].getlist();
		Node* upper = graph[i - 1].getlist();
		while (traverse != NULL)
		{
			if (traverse->element->character == ch)
			{
				
				if (upper->element->character == '#')
				{
					hash++;
					what = '#';
				}
				else if (upper->element->character == '|')
				{
					bar++;
					what = '|';
				}
				else if (upper->element->character == 'X')
				{
					X++;
					what = 'X';
				}
				else if (upper->element->character == '*')
				{
					what = '*';
				}
				else if (upper->element->character == '\xE2' || upper->element->character == '$' || upper->element->character == '!')
				{
					if (upper->element->character == '\xE2')
					{
						what = '\xE2';
					}
					else if (upper->element->character == '$')
					{
						what = '$';
					}
					else
					{
						what = '!';
					}
					GameElement* temp = new GameElement(upper->element->power, upper->element->character);
					collection.insert(temp);
					upper->element->character = '*';
				}
				else if (upper->element->character == 'E')
				{
					return 1;
				}
				char store = upper->element->character;
				upper->element->character = traverse->element->character;
				traverse->element->character = store;
					
					
				//}

			}
			upper = upper->next;
			traverse = traverse->next;
		}

	}
	return 0;
}
// leftturn
bool turnLeft(LinkedList*& graph, char ch, int size, CollectionOfPowerUps& collection, int& hash, int& bar, int& X, char& what)
{
	for (int i = 0; i < size; i++)
	{
		Node* traverse = graph[i].getlist();
		while (traverse->next != NULL)
		{
			if (traverse->next->element->character == ch)
			{
				if (traverse->element->character == '#')
				{
					hash++;
					what = '#';
				}
				else if (traverse->element->character == '|')
				{
					bar++;
					what = '|';
				}
				else if (traverse->element->character == 'X')
				{
					X++;
					what = 'X';
				}
				else if (traverse->element->character == '*')
				{
					what = '*';
				}
				else if (traverse->element->character == '\xE2' || traverse->element->character == '$' || traverse->element->character == '!')
				{
					if (traverse->element->character == '\xE2')
					{
						what = '\xE2';
					}
					else if (traverse->element->character == '$')
					{
						what = '$';
					}
					else
					{
						what = '!';
					}
					GameElement* temp = new GameElement(traverse->element->power, traverse->element->character);
					collection.insert(temp);
					traverse->element->character = '*';
				}
				else if (traverse->element->character == 'E' && traverse->next->element->character=='C')
				{
					return 1;
				}
				//if (traverse->element->character != '|')
				//{
					char store = traverse->next->element->character;
					traverse->next->element->character = traverse->element->character;
					traverse->element->character = store;
				//}

			}
			traverse = traverse->next;
		}
	}
	return 0;
}
void displayGraph(LinkedList* arr, int size)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << endl;
	int width = 75 - size;
	for (int i = 0; i < size; i++)
	{
		cout << setw(width);
		arr[i].display();
		cout << endl;
		
	}
	cout << endl;
}
void displayGraph(vector<int> vec, LinkedList* arr, int size)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
	cout << endl;
	int width = 75 - size;
	for (int i = 0; i < size; i++)
	{
		cout << setw(width);
		arr[i].display(vec);
		cout << endl;
		
	}
	cout << endl;
}
void countScore(int& score,char whatHit,int obstaclePowerHash, int obstaclePowerBar, int obstaclePowerX, int currentTime, CollectionOfPowerUps& collect)
{
	if (currentTime > 40)
	{
		score -= 1;
	}
	if (whatHit == '*')
	{
		score += 2;
	}
	else if (whatHit == '$')
	{
		score += collect.getVectorOfPower()[0];
	}
	else if (whatHit == '!')
	{
		score += collect.getVectorOfPower()[2];
	}
	else if (whatHit == '\xE2')
	{
		score += collect.getVectorOfPower()[1];
	}
	else if (whatHit == '#')
	{
		score -= obstaclePowerHash;
	}
	else if (whatHit == '|')
	{
		score -= obstaclePowerBar;
	}
	else if (whatHit == 'X')
	{
		score -= obstaclePowerX;
	}
}

























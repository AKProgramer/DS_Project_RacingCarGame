#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct GameElement
{
	static int nextID;
	int id;
	int weight;
	int power;
	char character;
	GameElement(int p, char c)
	{
		id = nextID++;
		power = p;
		character = c;
		if (c == '#' || c == '|' || c == 'X')
		{
			weight = 600 + (-1 * power);
		}
		else if (c == '$' || c == '\xE2' || c == '!')
		{
			weight = 40 + (-1 * power);
		}
		else if(c=='*')
		{
			weight = 100;
		}
		else
		{
			weight = 0;
		}
	}
};
int GameElement::nextID = 0;
struct Store
{
	GameElement* element;
	Store* next;
	Store(GameElement* element)
	{
		this->element = element;
		next = NULL;
	}
};
class Queue
{
	
	Store* front;
	Store* rear;
public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}
	GameElement* Front()
	{
		if (isEmpty())
		{
			return NULL;
		}
		else
		{

		return front->element;
		}
	}

	bool isEmpty()
	{
		if (front == NULL)
		{
			return 1;
		}
		return 0;
	}
	void enqueue(GameElement* data)
	{
		Store* newNode = new Store(data);
		if (isEmpty())
		{
			front = rear = newNode;
			return;
		}
		rear->next = newNode;
		rear = rear->next;
	}
	void dequeue()
	{
		Store* todelete = front;
		front = front->next;
		delete todelete;
	}
	int size()
	{
		Store* traverse = front;
		int count = 0;
		while (traverse != NULL)
		{
			count++;
			traverse = traverse->next;
		}
		return count;
	}
	void removeObstacleFromQueue()
	{
		while (isEmpty())
		{
			this->dequeue();
		}
	}

};

class CollectionOfPowerUps 
{
	struct Item
	{
		GameElement* element;
		Item* next;
		Item(GameElement* element)
		{
			this->element = element;
			next = NULL;
		}
	};
	Item* head;
public:
	CollectionOfPowerUps()
	{
		head = NULL;
	}
	Item* getItem()
	{
		return head;
	}
	// check
	void insert(GameElement* element)
	{
		Item* newItem = new Item(element);
		if (head == NULL)
		{
			head = newItem;
			return;
		}
		Item* traverse = head;
		while (traverse->next != NULL)
		{
			traverse = traverse->next;
		}
		traverse->next = newItem;
	}
	int* getVectorOfPower()
	{
		int* arr = new int[3];
		arr[0] = 0;
		arr[1] = 0;
		arr[2] = 0;
		Item* traverse = head;
		while (traverse != NULL)
		{
			if (traverse->element->character == '$')
			{
				arr[0]=traverse->element->power;
			}
			else if (traverse->element->character == '\xE2')
			{
				arr[1] = traverse->element->power;
			}
			else if (traverse->element->character == '!')
			{
				arr[2] = traverse->element->power;
			}
			
			traverse = traverse->next;
		}
		return arr;
	}
	void display()
	{
		Item* traverse = head;
		while (traverse != NULL)
		{
			cout << traverse->element->character << " ";
			traverse = traverse->next;
		}

	}
	void deleteCollectionOfPowerup()
	{
		if (head == NULL)
		{
			return;
		}
		Item* traverse = head;
		Item* toDelete;
		
		while (traverse != NULL)
		{
			toDelete = traverse->next;
			delete traverse;
			traverse = toDelete;
		}
		head = NULL;
	}
};

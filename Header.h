#pragma once
#include<iostream>
#include<string>
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
		weight = 0;
		id = nextID++;
		cout << "id for character " << c << " is " << id << endl;
		power = p;
		character = c;
	}
	GameElement()
	{
		weight = 0;
		id = nextID++;
		power = 0;
		character = '\0';
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
class queue
{
	
	Store* front;
	Store* rear;
public:
	queue()
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
	void display()
	{
		Item* traverse = head;
		while (traverse != NULL)
		{
			cout << traverse->element->character << " ";
			traverse = traverse->next;
		}

	}
};

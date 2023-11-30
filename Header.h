#pragma once
#include<iostream>
using namespace std;

class queue
{
	struct Node
	{
		char data;
		Node* next;
		Node(char d)
		{
			data = d;
			next = NULL;
		}
	};
	Node* front;
	Node* rear;
public:
	queue()
	{
		front = NULL;
		rear = NULL;
	}
	char Front()
	{
		if (isEmpty())
		{
			return '\0';
		}
		else
		{

		return front->data;
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
	void enqueue(int data)
	{
		Node* newNode = new Node(data);
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
		Node* todelete = front;
		front = front->next;
		delete todelete;
	}
	int size()
	{
		Node* traverse = front;
		int count = 0;
		while (traverse != NULL)
		{
			count++;
			traverse = traverse->next;
		}
		return count;
	}
	void display()
	{
		Node* traverse = front;
		while (traverse != NULL)
		{
			cout << traverse->data << " ";
			traverse = traverse->next;
		}
	}
};
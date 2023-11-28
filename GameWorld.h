#pragma once
#include<iostream>
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
		while (temp != NULL)
		{
			/*if (temp->data == '|')
			{
				cout << "      ";
			}else*/
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
	
};
void move(LinkedList*& graph, char ch, int size)
{
	for (int i = 0; i < size; i++)
	{
		Node* traverse = graph[i].getlist();

		while (traverse != NULL)
		{
			
			if (traverse->data == ch)
			{
				if (traverse->next != NULL && traverse->next->data != '|')
				{
					char store = traverse->next->data;
					traverse->next->data = traverse->data;
					traverse->data = store;
					traverse = traverse->next;
				}
			}
			traverse = traverse->next;
		}
		
	}
}
void moveRight(LinkedList*& graph, char ch, int size)
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
				if (right->data != '|')
				{
					char store = right->data;
					right->data = traverse->data;
					traverse->data = store;
					check = true;
				}
				
			}
			right = right->next;
			traverse = traverse->next;
		}
		if (check == true)
		{
			break;
		}
		
	}
}
void moveLeft(LinkedList*& graph, char ch, int size)
{
	for (int i = 1; i < size; i++)
	{
		bool check = false;
		Node* traverse = graph[i].getlist();
		Node* left = graph[i - 1].getlist();
		while (traverse != NULL)
		{
			if (traverse->data == ch)
			{
				if (left->data != '|')
				{
					char store = left->data;
					left->data = traverse->data;
					traverse->data = store;
					check = true;
				}

			}
			left = left->next;
			traverse = traverse->next;
		}
		if (check == true)
		{
			break;
		}

	}
}
void displayGraph(LinkedList* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i].display();
		cout << endl;
	}
}


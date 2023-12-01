#pragma once
#include<iostream>
#include"Header.h"
#include"GameWorld.h"
using namespace std;
class Graph
{
	int vertices;
	LinkedList* list;
public:
	Graph(int vertices)
	{
		this->vertices = vertices;
		list = new LinkedList[vertices];
		
	}
	void addEdge(int vertix, GameElement* element)
	{
		list[vertix].insert(element);
		
	}
	void display() {
		for (int i = 0; i < vertices; ++i) {
			Node* traverse = list[i].getlist();
			cout << "Vertix : " << traverse->element->id << " is connected with ";
			traverse = traverse->next;
			while (traverse->next != NULL)
			{
				cout << traverse->element->id<<" ";
				traverse = traverse->next;
			}
			cout << endl;
		}
	}

};
void insertingNodesInGraph(LinkedList* graph,int size)
{
	graph[0].display();
	graph[1].display();
	cout << size << endl;
	Graph actualGraph(size*size);
	int index = 0;
	//inserting first lists in graphs
	Node* traverse1 = graph[0].getlist();
	GameElement* previous1 = NULL;
	Node* lower = graph[1].getlist();
	while (traverse1 != NULL)
	{
		actualGraph.addEdge(index, previous1);
		actualGraph.addEdge(index, traverse1->element);
		if(traverse1->next!=NULL)
		actualGraph.addEdge(index, traverse1->next->element);
		actualGraph.addEdge(index, lower->element);

		previous1 = traverse1->element;
		traverse1 = traverse1->next;
		lower = lower->next;
		index++;
	}
	// Inserting middle list in graph
	for (int i = 1; i < size-1; i++)
	{
		Node* upper = graph[i-1].getlist();
		Node* traverse = graph[i].getlist();
		Node* lower = graph[i + 1].getlist();
		GameElement* previous = NULL;
		for (int j = 0; j < size; j++)
		{
			cout << index << endl;
				if(traverse->next!=NULL)
				actualGraph.addEdge(index, traverse->next->element);
				actualGraph.addEdge(index, traverse->element);
				actualGraph.addEdge(index, upper->element);
				actualGraph.addEdge(index, lower->element);
				actualGraph.addEdge(index, previous);
				// moving forward
				previous = traverse->element;
				traverse = traverse->next;
				upper = upper->next;
				lower = lower->next;
				index++;
			
			
		}
	}
	//Inserting last list in graph
	Node* traverse2 = graph[size - 1].getlist();
	GameElement* previous2 = NULL;
	Node* upper = graph[size - 2].getlist();
	while (traverse2 != NULL)
	{
		actualGraph.addEdge(index, previous2);
		actualGraph.addEdge(index, traverse2->element);
		if (traverse2->next != NULL)
			actualGraph.addEdge(index, traverse2->next->element);
		actualGraph.addEdge(index, upper->element);
		previous2 = traverse2->element;
		upper = upper->next;
		traverse2 = traverse2->next;
		index++;
	}

	actualGraph.display();

}
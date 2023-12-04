#pragma once
#include<iostream>
#include"GameElement.h"
#include"GameWorld.h"
#include<vector>
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
	vector<int> dijkstra() {
		int* distance = new int[vertices];
		bool* visited = new bool[vertices];
		int* parent = new int[vertices];
		int source = 0;
		int destination = 0;
		for (int i = 0; i < vertices; ++i) {
			distance[i] = INT_MAX;
			visited[i] = false;
			parent[i] = -1;
			list[i].getlist()->element->id = i;
			if (list[i].getlist()->element->character == 'C')
			{
				source = i;
			}
			if (list[i].getlist()->element->character == 'E')
			{
				destination = i;
			}
		}
		distance[source] = 0;

		for (int count = 0; count < vertices - 1; ++count) {
			int minDistance = INT_MAX;
			int minIndex = -1;
			for (int v = 0; v < vertices; ++v) {
				if (!visited[v] && distance[v] <= minDistance) {
					minDistance = distance[v];
					minIndex = v;
				}
			}
			           
			int u = minIndex;
			visited[u] = true;

			// Update distances of adjacent vertices
			Node* temp = list[u].getlist();
			while (temp != nullptr) {
				int v = temp->element->id;
				int weight = temp->element->weight;

				if (!visited[v] && distance[u] != INT_MAX && distance[u] + weight < distance[v]) {
					distance[v] = distance[u] + weight;
					parent[v] = u;
				}
				temp = temp->next;
			}
		}
		vector<int> vec;
		// Reconstruct the path from source to destination
		cout <<setw(80)<< "Shortest path from " << list[source].getlist()->element->character << " to " << list[destination].getlist()->element->character << ":\n";
		if (distance[destination] != INT_MAX) {
			int current = destination;
			cout <<setw(55)<< "Path : ";
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE);
			while (current != -1) {
				cout << list[current].getlist()->element->character <<" ";
				vec.push_back(current);
				current = parent[current];
			}
			SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << endl;
		}
		else {
				cout << "No path from " << source << " to " << destination << "!";
		}

		
		return vec;
	}

	// Helper function to find the vertex with minimum distance value

	int minDistance(int dist[], bool visited[]) {
		int min = INT_MAX, min_index;

		for (int v = 0; v < vertices; ++v) {
			if (visited[v] == false && dist[v] <= min) {
				min = dist[v];
				min_index = v;
			}
		}

		return min_index;
	}
	void display() {
		for (int i = 0; i < vertices; ++i) {
			Node* traverse = list[i].getlist();
			while (traverse != NULL)   
			{
				traverse = traverse->next;
			}
			cout << endl;
		}
	}

};
int insertingNodesInGraph(LinkedList* graph, int size)
{
	if (graph == NULL)
	{
		return 0;
	}
	Graph actualGraph(size * size);
	int index = 0;
	//inserting first lists in graphs
	Node* traverse1 = graph[0].getlist();

	GameElement* previous1 = NULL;
	Node* lower = graph[1].getlist();;

	while (traverse1 != NULL)
	{
		actualGraph.addEdge(index, traverse1->element);
		actualGraph.addEdge(index, previous1);
		if (traverse1->next != NULL)
			actualGraph.addEdge(index, traverse1->next->element);
		actualGraph.addEdge(index, lower->element);
		previous1 = traverse1->element;
		traverse1 = traverse1->next;
		lower = lower->next;
		index++;
	}
	//Inserting middle list in graph
	for (int i = 1; i < size - 1; i++)
	{
		Node* upper = graph[i - 1].getlist();
		Node* traverse = graph[i].getlist();
		Node* lower = graph[i + 1].getlist();
		GameElement* previous = NULL;
		while (traverse != NULL)
		{
			actualGraph.addEdge(index, traverse->element);
			if (traverse->next != NULL)
				actualGraph.addEdge(index, traverse->next->element);
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
	//cout << index << endl;
	////Inserting last list in graph
	Node* traverse2 = graph[size - 1].getlist();
	GameElement* previous2 = NULL;
	Node* upper = graph[size - 2].getlist();
	while (traverse2 != NULL)
	{
		actualGraph.addEdge(index, traverse2->element);
		actualGraph.addEdge(index, previous2);
		if (traverse2->next != NULL)
			actualGraph.addEdge(index, traverse2->next->element);
		actualGraph.addEdge(index, upper->element);
		previous2 = traverse2->element;
		upper = upper->next;
		traverse2 = traverse2->next;
		index++;
	}

	vector<int> vec=actualGraph.dijkstra();
	return vec.size();
}
#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
struct User
{
	string name;
	string score;
};
void createFileAndStoreScore(string name, int score)
{
	ofstream fout;
	fout.open("StoringUserScores.txt", ios::app);
	if (!fout.is_open())
	{
		cout << "ERROR : file can't open" << endl;
	}
	else
	{
		fout << name;
		fout << endl;
		fout << score;
		fout << endl;
	}
}

class LeaderBoard
{
	struct Node
	{
		User data;
		Node* left;
		Node* right;
		Node(User d)
		{
			data = d;
			left = NULL;
			right = NULL;
		}
	};
	Node* head;
	int rank;
	void insertingScoreInBST(Node*& root, User user)
	{
		if (root == NULL)
		{
			root = new Node(user);
		}
		if (stoi(root->data.score) > stoi(user.score))
		{
			insertingScoreInBST(root->left, user);
		}
		else if (stoi(root->data.score) < stoi(user.score))
		{
			insertingScoreInBST(root->right, user);
		}

	}
	void readFile()
	{
		ifstream fin;
		fin.open("StoringUserScores.txt", ios::app);
		if (!fin.is_open())
		{
			cout << "ERROR : file can't open" << endl;
		}
		else
		{
			string str;
			while (getline(fin, str))
			{
				User user;
				user.name = str;
				getline(fin, str);
				user.score = str;
				insertingScoreInBST(head, user);
			}
		}
	}
	
public:
	Node* getHead()
	{
		 rank=1;
		return head;
	}
	LeaderBoard()
	{
		head = NULL;
		readFile();
	}
	
	void printScores(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		printScores(root->right);
		 cout <<setw(45)<< "|" <<setw(10)<< rank++<<setw(20) << root->data.name<<setw(20) << root->data.score<<setw(5)<<"|"<< endl;
		printScores(root->left);
	}
};

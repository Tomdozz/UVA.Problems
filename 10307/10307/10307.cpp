// 10307.cpp : Defines the entry point for the console application.
//

//#define _CRT_SECURE_NO_WARNINGS
#include "stdafx.h"
#include "math.h"
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <list>
#include <algorithm>
#include <limits>
#include <time.h>

#define INF 200
#define MAX 51;

using namespace std;

int n, x, y, s;
string input;

char matrix[51][51];
int distM[51][51];
int parent[51];


struct Node
{
	int x, y, step;
	char type;
};

struct Edge
{
	int u, v, w;
};

vector<Edge> edges;
vector<Node> nodes;

void BFS(int s);
void Reset(int x, int y);
void MakeSet(int index);
int Find(int index);
bool Union(int u, int v);
bool Compare(Edge const &a, Edge const &b);
int MST();

void PrintGraph()
{
	for (size_t i = 0; i < x; i++)
	{
		for (size_t j = 0; j < y; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}

int main()
{
	scanf_s("%d", &n);
	while (n--)
	{
		scanf_s("%d %d", &x, &y);

		for (int i = 0; i < y; i++)
		{
			input.clear();
			getline(cin, input);
			while (input.length() == 0)
			{
				getline(cin, input);
			}
			for (int j = 0; j < x - 1; j++)
			{
				matrix[i][j] = input[j];

				if (input[j] == 'S' || input[j] == 'A')
				{
					Node n = { j,i,0,input[j] };
					nodes.push_back(n);
				}
				if (input[j] == 'S')
				{
					s = nodes.size() - 1;
				}
			}
		}

		PrintGraph();
		if (nodes.size() > 0)
		{
			Node temp = nodes[0];
			nodes[0] = nodes[s];
			nodes[s] = temp;
		}

		for (int i = 0; i < nodes.size(); i++)
		{
			Reset(x, y);
			BFS(i);
		}
		//for each (Node n in nodes)
		//{
		//	cout << "x" << n.x << endl;
		//	cout << "y" << n.y << endl;
		//	cout << "type" << n.type << endl;
		//	cout << "step" << n.step << endl;
		cout << MST() << endl;
	}
	//do bfs for all nodes
	//for each (Edge e in edges)
	//{
	//	cout << "u" << e.u << endl;
	//	cout << "v" << e.v << endl;
	//	cout << "w" << e.w << endl;
	//}
	int d;
	cin >> d;
	return 0;
}

void Reset(int x, int y)
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			distM[i][j] = 0;
		}
	}
}
void BFS(int s)
{
	queue<Node> pq;
	pq.push(nodes[s]);

	while (!pq.empty())
	{
		Node t = pq.front();//take out first element in pq
		pq.pop();
		if ((t.type == 'A' || t.type == 'S') && t.step > 0)
		{
			for (int i = 0; i < nodes.size(); i++)
			{
				if (nodes[i].y == t.y && nodes[i].x == t.x)
				{
					Edge e = { s,i,t.step };
					edges.push_back(e);
					if (matrix[t.x][t.y] == 'S') //if i find myself
						return;
				}
			}
		}
		t.step++;
		if (matrix[t.y + 1][t.x] != '#' && distM[t.y + 1][t.x] == 0) //Down
		{
			distM[t.y + 1][t.x] = 1;
			Node temp2 = { t.x, t.y + 1, t.step, distM[t.y + 1][t.x] };
			pq.push(temp2);
		}
		if (matrix[t.y - 1][t.x] != '#' && distM[t.y - 1][t.x] == 0) //Up
		{
			distM[t.y - 1][t.x] = 1;
			Node temp2 = { t.x, t.y - 1, t.step, matrix[t.y - 1][t.x] };
			pq.push(temp2);
		}
		if (matrix[t.y][t.x + 1] != '#' && distM[t.y][t.x + 1] == 0) //Right
		{
			distM[t.y][t.x + 1] = 1;
			Node temp2 = { t.x + 1, t.y, t.step, matrix[t.y][t.x + 1] };
			pq.push(temp2);
		}
		if (matrix[t.y][t.x - 1] != '#' && distM[t.y][t.x - 1] == 0) //Left
		{
			distM[t.y][t.x - 1] = 1;
			Node temp2 = { t.x - 1, t.y, t.step, matrix[t.y][t.x - 1] };
			pq.push(temp2);
		}
	}
}

void MakeSet(int index)
{
	parent[index] = index;
}
int Find(int index)
{
	if (parent[index] == index)
	{
		return index;
	}
	return Find(parent[index]);
}
bool Union(int u, int v)
{
	int PX = Find(u);
	int PY = Find(v);
	if (PX == PY)
	{
		return false;
	}
	parent[PX] = PY;
	return true;
}
bool Compare(Edge const &a, Edge const &b)
{
	return a.w < b.w;
}
int MST()
{
	int steps = 0;
	sort(edges.begin(), edges.end(), &Compare); //Sort on ascending

	for (int i = 0; i < nodes.size(); i++)
	{
		MakeSet(i);
	}
	//for each edge check if u and v belongs to different sets
		//add edge to tree
		//make u and v in one sigle set
	for (int j = 0; j < edges.size(); j++)
	{
		if (Union(edges[j].u, edges[j].v))
		{
			steps += edges[j].w;
		}
	}
	return steps;
}


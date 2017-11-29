// 116.Undirectional.TSP.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#define INT_MAX 2637253
#include <algorithm>
#include <climits>
#include <cstdio>

using namespace  std;

int matrix[11][101];
//from a point in a array how long until i get out
int cost[11][101];

int path[11][101];

int colums;
int rows;

void Print(int rows, int colums);
int FindPath(int columStart, int row);
int Path(int i, int j);

int main()
{
	while (cin >> rows >> colums)
	{

		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < colums; c++)
			{
				scanf_s("%d", &matrix[r][c]);
				cost[r][c] = INT_MAX;
			}
		}

		int ans = INT_MAX;
		int whatPath = 0; //witch to start on
		for (int i = 0; i < rows; i++)
		{
			FindPath(i, 0);
			if (cost[i][0] < ans)
			{
				ans = cost[i][0];
				whatPath = i;
			}
		}

		for (size_t i = 0; i < colums; i++)
		{
			printf(i == 0 ? "%d" : " %d", whatPath + 1);

			whatPath = path[whatPath][i];
		}
		printf("\n%d\n", ans);
	}
	cin >> rows;
	return 0;
}

int FindPath(int row, int c)
{
	//int	val = 0;
	if (c >= row);
	if (cost[row][c] != INT_MAX) { return cost[row][c]; }
	int dir[3] = { row - 1,row, row + 1 };

	//if we are att the top or the bottom
	if (row == 0) { dir[0] = rows - 1; }
	if (row == rows - 1) { dir[2] = 0; }

	for (size_t i = 0; i < 3; i++)
	{
		int val = matrix[row][c] + FindPath(dir[i], c + 1);

		//check if my value is better that the one that is in the matrix
		if (cost[row][c] > val || (cost[row][c] == val&&path[row][c] > dir[i]))
		{
			cost[row][c] = val;
			//what riw do i go to from here, basically what row to go to from here
			path[row][c] = dir[i];
		}
	}
	return cost[row][c];
}
//int Path(int i, int j)
//{
//	int one = i - 1;
//	int two = i;
//	int three = i + 2;;
//	//for s= 2 
//	//int val = matrix[i][j] + path
//}

//int FindPath(int c, int row)
//{
//	int val = 0;
//	if (matrix[row][c + 1] < matrix[row + 1][c + 1] && matrix[row][c + 1] < matrix[row - 1][c + 1])
//	{
//		w[row][c + 1] = matrix[row][c + 1];
//		val = matrix[row][c] + FindPath(row, c + 1);
//		//matrix[row][c + 1];
//	}
//
//	else if (matrix[row + 1][c + 1] < matrix[row][c + 1] && matrix[row + 1][c + 1] < matrix[row - 1][c + 1])
//	{
//		w[row + 1][c + 1] = matrix[row + 1][c + 1];
//		val = matrix[row][c] + FindPath(row + 1, c + 1);
//		//matrix[row + 1][c + 1];
//	}
//
//	else if (matrix[row - 1][c + 1] < matrix[row][c + 1] && matrix[row - 1][c + 1] < matrix[row + 1][c + 1])
//	{
//		w[row - 1][c + 1] = matrix[row - 1][c + 1];
//		val = matrix[row][c] + FindPath(row - 1, c + 1);
//		//matrix[row - 1][c + 1];
//	}
//
//	return val;
//
//}

void Print(int rows, int colums)
{
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < colums; j++)
		{
			cout << matrix[i][j];
		}
		cout << endl;
	}
}


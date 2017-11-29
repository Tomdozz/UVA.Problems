// 10078.The.Art.Gallery.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

//n is number of corners
int N;
bool convex;

struct Corner
{
	int x;
	int y;
};

double Cross(Corner p1, Corner p2, Corner p3);
int main()
{
	//vector<Corner> corners;
	scanf_s("%d", &N);
	while (N != 0)
	{
		Corner corners[51];
		for (int i = 0; i < N; i++)
		{
			//Corner temp;
			scanf_s("%d %d", &corners[i].x, &corners[i].y);
		}
		corners[N] = corners[0];
		corners[N+1] = corners[1];

		convex = true;
		double d = Cross(corners[0], corners[1], corners[2]);
		for (int i = 1; i < N; i++)
		{
			int compare = d;
			Corner a = corners[i];
			Corner b = corners[i + 1];
			Corner c = corners[i + 2];
			d = Cross(a, b, c);

			if (compare *d < 0)
			{
				convex = false;
				break;
			}
		}
		if (convex)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}

		scanf_s("%d", &N);
	}
	return 0;
}
double Cross(Corner p1, Corner p2, Corner p3)
{
	double x1 = p2.x - p1.x;
	double x2 = p3.x - p1.x;
	double y1 = p2.y - p1.y;
	double y2 = p3.y - p1.y;
	return x1*y2 - x2*y1;
}


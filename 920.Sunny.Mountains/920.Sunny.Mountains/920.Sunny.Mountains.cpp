// 920.Sunny.Mountains.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>


using namespace std;

int C;
int N;
int tempX, tempY;
int currMaxY;
double ans;

struct Point
{
	int x;
	int y;
};

bool Compare(const Point &a, const Point &b);

int main()
{
	scanf_s("%d", &C);
	while (C--)
	{
		scanf_s("%d", &N);
		vector<Point> points;
		for (int i = 0; i < N; i++)
		{
			Point temp;
			scanf_s("%d %d", &temp.x, &temp.y);
			points.push_back(temp);
		}

		//sort on x so that all coordinates are in right order
		sort(points.begin(), points.end(), Compare);

		currMaxY = 0;
		ans = 0;
		for (int i = 0; i < points.size(); i++)
		{
			//only if next peak is above current maxpoint we can get a new max
			if (points[i].y > currMaxY)
			{
				//distFormula
				//d= sqrt((x2-x1)^2+(y2-y1)^2)
				double d = sqrt((double)(points[i].x - points[i - 1].x) * (points[i].x - points[i - 1].x)
					+ (points[i].y - points[i - 1].y) * (points[i].y - points[i - 1].y));
				ans += d * (points[i].y - currMaxY)
					/ (points[i].y - points[i - 1].y);
				currMaxY = points[i].y;
			}
		}
		cout << setprecision(2)
			<< setiosflags(ios::fixed)
			<< ans << endl;
		//cin >> ans;
	}
	return 0;
}

bool Compare(const Point &a, const Point &b)
{
	return b.x < a.x;
}


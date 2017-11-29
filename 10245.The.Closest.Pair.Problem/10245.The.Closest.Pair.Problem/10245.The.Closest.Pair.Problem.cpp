// 10245.The.Closest.Pair.Problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
//D&C

int N;
struct Point
{
	int x;
	int y;
};

//Compare on x to make the array sorted from smallest to biggest x
bool compare(Point a, Point b)
{
	return a.x < b.x;
}

double EuclideanDist(Point p0, Point p1);
double Divide(Point arr[], int low, int high);
double Combine(Point arr[], int low, int mid, int high, double minLeft, double minRight);
//double Merge();

int main()
{
	scanf_s("%d", &N);
	Point points[10000 + 1];
	while (N != 0)
	{
		//vector<pair<double,double>> points[10000+1];

		for (int i = 0; i < N; i++)
		{

			scanf_s("%d %d", &points[i].x, &points[i].y);
		}
		sort(points, points + N, compare);
		double ans = Divide(points, 0, N);
		if (ans >= 10000.0)
		{

			printf("INFINITY\n");
		}
		else
		{
			printf("%.4lf\n", ans);
		}
		scanf_s("%d", &N);
	}

	return 0;
}

double Divide(Point arr[], int low, int high)
{
	if (low >= high)
	{
		return 99999;
	}
	//select midpoint
	int mid = (low + high) / 2;
	//divide each subarray
	double left = Divide(arr, low, mid);
	double right = Divide(arr, mid + 1, high);
	return Combine(arr, low, mid, high, left, right);
}

double Combine(Point arr[], int low, int mid, int high, double minLeft, double minRight)
{
	double d = (minLeft<minRight) ? minLeft : minRight;
	double line = (double)(arr[mid].x + arr[mid + 1].x)*0.5; 
	double min_D = d;
	for (int i = mid + 1; arr[i].x<line + d && i <= high; i++)
	{ 
		for (int j = mid; arr[j].x>line - d && j >= low; j--) 
		{
			double temp = EuclideanDist(arr[i], arr[j]);
			if (temp<min_D) min_D = temp;
		}
	}
	return min_D;
}

double EuclideanDist(Point p0, Point p1)
{
	return sqrt(((p0.x - p1.x)*(p0.x - p1.x)) + ((p0.y - p1.y)*(p0.y - p1.y)));
}

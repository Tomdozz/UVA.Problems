// 10300.Ecological.Premium.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n, f, s, a, e;
	int score;
	scanf_s("%d", &n);
	
	//looping all the test cases
	for (size_t i = 0; i < n; i++)
	{
		scanf_s("%d", &f);
		score = 0;
		//loops all the framers in each tetscase and calculates their premium
		for (size_t j = 0; j < f; j++)
		{
			scanf_s("%d %d %d", &s, &a, &e);
			//The calculation for calculationg the score/ money can be shortend
			score += s*e;
						
		}
		printf("%d\n", score);
	}
	//cin >> n;
	return 0;
}


// 839.Not.So.Mobile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
int CheckBalance();
bool bal = true;

int main()
{
	int n;
	scanf_s("%d", &n);

	while (n--)
	{
		bal = true;
		CheckBalance();
		if (bal) {
			printf("YES\n");
		}
		else {
			printf("NO\n");
		}
		if (n)puts("");
	}
	//puts("");
	return 0;
}


int CheckBalance()
{
	int w1, d1, w2, d2;
	scanf_s("%d %d %d %d", &w1, &d1, &w2, &d2);

	if (w1 == 0)
	{
		w1 = CheckBalance();
	}
	if (w2 == 0)
	{
		w2 = CheckBalance();
	}

	if (w1*d1 != w2*d2)	bal = false;
	return w1 + w2;
}




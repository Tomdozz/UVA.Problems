// 10340.All.in.All.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

string t;
string s;
int main()
{
	while (cin >> s >> t)
	{
		int count = 0;
		int i = 0;
		while (i < t.size() && count < s.size())
		{
			if (t[i] == s[count])
			{
				count++;
				i++;
			}
			else
				i++;
		}
		if (count == s.size())
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}


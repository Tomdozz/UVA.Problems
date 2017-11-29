// 185.Roman.numerals.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

const string ch[] = { "I","IV","V","IX","X","XL","L","XC","C","CD","D","CM", "M" };
const char ch2[] = { 'I','V','X','L','C','D','M' };
int value2[] = { 1,5,10,50,100,500,1000 };
int value[] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000 };

string temp;
string testString;
bool arabic;
bool roman;
bool ambigous;

char *val1;
char *val2;
int pos1, pos2;

string matrix[10][4] =
{
	/*0*/{" "," "," "," "},
	/*1*/{"M","C","X","I"},
	/*2*/{"MM","CC","XX","II" },
	/*3*/{"MMM","CCC","XXX","III" },
	/*4*/{" ","CD","XL","IV" },
	/*5*/{" ","D","L","V" },
	/*6*/{" ","DC","LX","VI" },
	/*7*/{" ","DCC","LXX","VII" },
	/*8*/{" ","DCCC","LXXX","VIII" },
	/*9*/{" ","CM","XC","IX" },
};

void Check(string first, string second, string ans);
int Val(char r);
int RomanToNR(string &str);

int main()
{
	while (cin >> temp)
	{
		val1 = new char[9];
		val2 = new char[9];
		if (temp == "#") { break; }
		for (size_t i = 0; i < temp.size(); i++)
		{
			if (temp.at(i) == '+') { pos1 = i; }
			if (temp.at(i) == '=') { pos2 = i; }
		}
		string str1 = temp.substr(0, pos1);
		string str2 = temp.substr(pos1 + 1, pos2 - pos1 - 1);
		string str3 = temp.substr(pos2 + 1);

		Check(str1, str2, str3);
		cout << arabic;
	}
	return 0;
}

int Val(char r)
{
	for (int i = 0; i < 13; i++)
	{
		if (ch2[i] == r)
		{
			return value2[i];
		}
	}
}
int RomanToNR(string &str)
{
	int result = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		//value of char at s[i]
		int s1 = Val(str[i]);

		if (i + 1 < str.length())
		{
			//value of char at s[i+1] 
			int s2 = Val(str[i + 1]);

			//compare values
			if (s1 >= s2)
			{
				result = result + s1;
			}
			else
			{
				//value of curren symbol is lessthan next->minus
				result = result + s2 - s1;
				i++;
			}
		}
		else
		{
			result = result + s1;
			i++;
		}
	}
	return result;
}

void Check(string first, string second, string ans)
{
	int firstNum = RomanToNR(first);
	int secondNum = RomanToNR(second);
	int ansNum = RomanToNR(ans);

	if (firstNum + secondNum == ansNum)
	{
		cout << "Correct ";
	}
	else
	{
		cout << "Incorrect ";
	}
}


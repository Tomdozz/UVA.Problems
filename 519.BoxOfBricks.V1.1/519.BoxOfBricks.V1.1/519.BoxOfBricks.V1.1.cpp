// 519.BoxOfBricks.V1.1.cpp : Defines the entry point for the console application.
//

		//cout << "Set #" << set << endl << "The minimum number of moves is " << EavenOut(arr, height, n - 1) << "."<<endl;
#include "stdafx.h"
#include <cstdio>
#include <stdio.h>
#include <iostream>
using namespace std;

//Forward declarations
int EavenOut(int arr[], int height, int n);
void QuickSort(int arr[], int left, int right);


int main()
{
	int n;
	int set = 0;
	scanf_s("%d", &n);

	//"mainloop"
	while (n != 0)
	{
		int sum = 0;
		int * arr = new int[n];
		int temp = 0;

		//Reading in to array and calculation the full sum of the array
		for (size_t i = 0; i < n; i++)
		{
			cin >> arr[i];
			//arr[i] = temp;
			sum += arr[i];
		}

		//Calls the quicksort method to sort the array
		QuickSort(arr, 0, n - 1);
		
		//Calculation the height of each pilar
		int height = sum / n;

		//Incrementing the set number to
		set++;

		printf("Set #%d\nThe minimum number of moves is %d.\n\n", set, EavenOut(arr, height, n - 1));
		cin >> n;
	}
}
int EavenOut(int arr[], int height, int n)
{
	int count = 0;
	int *min = arr;
	int *max = arr + n;

	while (min != max)
	{
		if (*min < height)
		{
			if (*max > height)
			{
				*max -= 1;
				*min += 1;
				count++;
			}
			else if (*max <= height)
			{
				*max--;
			}
		}
		else if (*max >= height)
		{
			*min++;
		}
	}
	return count;

}

//Method used to Sort an array
void QuickSort(int arr[], int left, int right)
{
	int i = left;
	int j = right;
	int temp = 0;

	//Select a pivot in the mittle 
	int pivot = arr[(left + right) / 2];
 
	while (i <= j)
	{
		/*Partitioning*/
		//while the value of arr[i] we move i closer to the pivot by incrementing i
		while (arr[i] < pivot)
		{
			i++;
		}

		//while the value of arr[j] we move it closer to the pivot by decreasing it
		while (arr[j] > pivot)
		{
			j--;
		}
		//Swaping method
		//We do this by saving the value of arr[i] to a temporary int 
		//Then the value of arr[i] becomes thr value och arr[j] 
		//Then arr[j] becomes the saved value
		if (i <= j)
		{
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			i++;
			j--;
		}
	}

	/*Recursivley call quickSort*/
	if (left < j)
	{
		QuickSort(arr, left, j);
	}
	if (i < right)
	{
		QuickSort(arr, i, right);
	}
		//if i is smaller than j we need to swap these
}


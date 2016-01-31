/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/
#include<stdlib.h>
int findSingleOccurenceNumber(int *a, int n)
{
	if (a == NULL)
		return -1;
	int i = 0, j = 0, flag = 0;
	for (; i<n; i++)
	{
		for (j = 0; j<n; j++)
		{
			flag = 0;
			if (i != j && a[i] == a[j])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
			return a[i];
	}
}
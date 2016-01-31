/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>
struct transaction
{
	int amount;
	char date[11];
	char description[20];
};
void reverseUptoALength(char *a, int m, int n)
{
	int i = m, j = n - 1;
	char temp;
	for (; i<j; i++, j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}
void reverseDates(char *a)
{
	int i = 0, j = strlen(a), count = 0, prev = 0;
	reverseUptoALength(a, 0, strlen(a));
	for (; i<j; i++)
	{
		if (a[i] != '-')
			count++;
		else
		{
			reverseUptoALength(a, prev, count);
			prev = count + 1;
		}
	}
	reverseUptoALength(a, prev, count);
}
int countGreaterNumbers(struct transaction *a, int n, char *date)
{
	int i = 0, count = 0;
	char t[11], t2[11];
	strcpy(t, date);
	reverseDates(t);
	for (; i<n; i++)
	{
		strcpy(t2, a[i].date);
		reverseDates(t2);
		if (strcmp(t, t2)<0)
			count++;
	}
	return count;
}

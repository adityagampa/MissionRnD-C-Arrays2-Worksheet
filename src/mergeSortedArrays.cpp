/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

/*#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	return NULL;
}*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
struct transaction
{
	int amount;
	char date[11];
	char description[20];
};
void reverseUptoaLength(char *a, int m, int n)
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
void reverseDate(char *a)
{
	int i = 0, j = strlen(a), count = 0, prev = 0;
	reverseUptoaLength(a, 0, strlen(a));
	for (; i<j; i++)
	{
		if (a[i] != '-')
			count++;
		else
		{
			reverseUptoaLength(a, prev, count);
			prev = count + 1;
		}
	}
	reverseUptoaLength(a, prev, count);
}
struct transaction * mergeSortedArrays(struct transaction *a, int alen, struct transaction *b, int blen)
{
	if (a == NULL || b == NULL)
		return NULL;
	struct transaction *c = (struct transaction *)malloc((alen + blen)*sizeof(struct transaction));
	char t1[11], t2[11];
	int i = 0, j = 0, k = 0;
	for (; i<alen && j<blen;)
	{
		strcpy(t1, a[i].date);
		strcpy(t2, b[j].date);
		reverseDate(t1);
		reverseDate(t2);
		if (strcmp(t1, t2) == 0)
		{
			strcpy(c[k].date, a[i].date);
			strcpy(c[k].description, a[i].description);
			c[k].amount = a[i].amount;
			k++;
			i++;
			strcpy(c[k].date, b[j].date);
			strcpy(c[k].description, b[j].description);
			c[k].amount = b[j].amount;
			k++;
			j++;
		}
		else if (strcmp(t1, t2) > 0)
		{
			strcpy(c[k].date, b[j].date);
			strcpy(c[k].description, b[j].description);
			c[k].amount = b[j].amount;
			k++;
			j++;
		}
		else
		{
			strcpy(c[k].date, a[i].date);
			strcpy(c[k].description, a[i].description);
			c[k].amount = a[i].amount;
			k++;
			i++;
		}
	}
	if (i == alen)
	{
		for (; j<blen; j++, k++)
		{
			strcpy(t2, b[j].date);
			reverseDate(t2);
			strcpy(c[k].date, b[j].date);
			strcpy(c[k].description, b[j].description);
			c[k].amount = b[j].amount;
		}
	}
	else if (j == blen)
	{
		for (; i<alen; i++, k++)
		{
			strcpy(t1, a[i].date);
			reverseDate(t1);
			strcpy(c[k].date, a[i].date);
			strcpy(c[k].description, a[i].description);
			c[k].amount = a[i].amount;
		}
	}
	return c;
}

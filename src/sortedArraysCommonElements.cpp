/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

/*#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	return NULL;
}
*/
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
void reverse1(char *a)
{
	int i = 0, j = strlen(a) - 1;
	char temp;
	for (; i <= j; i++, j--)
	{
		temp = a[i];
		a[i] = a[j];
		a[j] = temp;
	}
}
struct transaction * sortedArraysCommonElements(struct transaction *a, int alen, struct transaction *b, int blen)
{
	if (a == NULL || b == NULL)
		return NULL;
	int min = (alen>blen) ? blen : alen;
	struct transaction *c = (struct transaction *)malloc(min*sizeof(struct transaction));
	min = 0;
	int i = 0, j = 0;
	for (; i<alen && j<blen;)
	{
		reverse1(a[i].date);
		reverse1(b[j].date);
		if (strcmp(a[i].date, b[j].date) == 0)
		{
			strcpy(c[i].date, a[i].date);
			reverse1(c[i].date);
			strcpy(c[i].description, a[i].description);
			c[i].amount = a[i].amount;
			i++;
			j++;
			min++;
		}
		else if (strcmp(a[i].date, b[j].date)<0)
			i++;
		else
			j++;
	}
	if (min)
		return c;
	return NULL;
}

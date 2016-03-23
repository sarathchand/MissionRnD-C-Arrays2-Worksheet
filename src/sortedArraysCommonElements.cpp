/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int compare2(char *dob1, char* dob2);
int stringcompare2(char *s, char *y);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j = 0, k = 0;
	struct transaction *c = (struct transaction*)malloc(sizeof(struct transaction)*(ALen + BLen));
	if ((A != NULL) && (B != NULL))
	{
		while ((i < ALen) && (j < BLen))
		{
			if (compare2(A[i].date, B[j].date) == 1)
			{
				c[k] = A[i];
				i++;
				k++;
			}
			else
			{
				c[k] = B[j];
				j++;
				k++;

			}
		}
		while (i < ALen)
		{
			c[k] = A[i];
			i++;
			k++;
		}
		while (j < BLen)
		{
			c[k] = B[j];
			j++;
			k++;
		}
		realloc(c, sizeof(struct transaction)*k);
		struct transaction *d = (struct transaction*)malloc(sizeof(struct transaction)*(ALen + BLen));
		j = 0;
		for (i = 0; i < k - 1; i++)
		{
			if (stringcompare2(c[i].date, c[i + 1].date))
			{
				d[j] = c[i];
				j++;

			}
		}
		if (j != 0)
		{
			realloc(d, sizeof(struct transaction)*j);


			return d;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}


int compare2(char *dob1, char* dob2)
{
	int y1, y2, m1, m2, d1, d2, p = -1;

	y1 = (dob1[9] - '0') * 1 + (dob1[8] - '0') * 10 + (dob1[7] - '0') * 100 + (dob1[6] - '0') * 1000;
	y2 = (dob2[9] - '0') * 1 + (dob2[8] - '0') * 10 + (dob2[7] - '0') * 100 + (dob2[6] - '0') * 1000;
	if (y1 == y2)
	{
		m1 = (dob1[3] - '0') * 10 + (dob1[4] - '0') * 1;
		m2 = (dob2[3] - '0') * 10 + (dob2[4] - '0') * 1;
		if (m1 == m2)
		{
			d1 = (dob1[0] - '0') * 10 + (dob1[1] - '0') * 1;
			d2 = (dob2[0] - '0') * 10 + (dob2[1] - '0') * 1;
			if (d1 == d2)
			{
				p = 0;
			}
			else
			{
				if (d1 < d2)
				{
					return 1;
				}
				else
				{
					return 2;
				}
			}

		}
		else
		{
			if (m1 < m2)
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
	else
	{
		if (y1 < y2)
		{
			return 1;
		}
		else
		{
			return 2;
		}
	}
	if (p == 0)
	{
		return 0;
	}
}

int stringcompare2(char *s, char *y)
{
	int i, j, k = 0, p = 0, q = 0;
	for (i = 0; s[i] != '\0'; i++);
	for (j = 0; y[j] != '\0'; j++);
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == y[p])
		{
			k++;
		}
		else
		{
			break;
		}
		p++;
	}
	if ((k == i) && (k == j))
	{
		return 1;
	}
	else
	{
		return 0;
	}

}
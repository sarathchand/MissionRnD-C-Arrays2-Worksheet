/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
int compare1(char *dob1, char* dob2);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j = 0, k = 0;
	struct transaction *c = (struct transaction*)malloc(sizeof(struct transaction)*(ALen + BLen));
	if ((A != NULL) && (B != NULL))
	{
		while ((i < ALen) && (j < BLen))
		{
			if (compare1(A[i].date, B[j].date) == 1)
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
		/*for (i = 0; i < k; i++)
		{
			printf("%s", c[i].date);
		}*/

		return c;
	}
	else
	{
		return NULL;
	}
}



int compare1(char *dob1, char* dob2)
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


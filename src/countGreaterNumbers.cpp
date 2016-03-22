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
int compare(char *dob1, char* dob2);

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, c = 0;
	if ((Arr) && len < 0)
	{
		return -1;

	}
	else
	{
		for (i = 0; i < len; i++)
		{
			if (compare(Arr[i].date, date))
			{
				c++;
			}

		}
		return c;
	}

}
int compare(char *dob1, char* dob2)
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
					return 0;
				}
				else
				{
					return 1;
				}
			}

		}
		else
		{
			if (m1 < m2)
			{
				return 0;
			}
			else
			{
				return 1;
			}
		}
	}
	else
	{
		if (y1 < y2)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}
	if (p == 0)
	{
		return 0;
	}
}

#include <stdio.h>

#define MONTHS 12

int main()
{
	char *month[MONTHS] = {
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
   		"September",
		"October",
		"November",
		"December" };
	int avg_high_temp[MONTHS] = {
		35,
		41,
		49,
		58,
		67,
		74,
		83,
		84,
		74,
		60,
		43,
		36 };
	int x,bar;

	for(x=0;x<MONTHS;x++)
	{
		printf("%-9s| ",month[x]);
		for(bar=0;bar<avg_high_temp[x]/2;bar++)
			putchar('*');
		putchar('\n');
	}

	return(0);
}

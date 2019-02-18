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
	int t,m;

	/* Vertical axis */
	puts("Temp");
	for(t=90;t>31;t-=3)
	{
		printf("%3d | ",t);
		for(m=0;m<MONTHS;m++)
		{
			if(avg_high_temp[m] > t)
				printf("*   ");	/* 3 spaces after '*' */
			else
				printf("    ");	/* 4 spaces */
		}
		putchar('\n');
	}

	/* Horizontal axis */
	printf("     ");		/* 5 spaces */
	for(m=0;m<MONTHS;m++)
	{
		printf("%3.3s ",month[m]);
	}
	putchar('\n');

	return(0);
}

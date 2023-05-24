#include<stdio.h>

int main(void)
{
	int a1;
	int a2;
	int a3;
	float avg;

	printf("\nEnter first number: ");
	fflush(stdout);
	scanf("%d", &a1);

	printf("Enter second number: ");
	fflush(stdout);
	scanf("%d", &a2);

	printf("Enter third number: ");
	fflush(stdout);
	scanf("%d", &a3);

	avg = (a1 + a2 + a3) / 3;

	printf("Avg is: %f", avg);
	while(getchar() != '\n'){}
	getchar();

	return 0;
}

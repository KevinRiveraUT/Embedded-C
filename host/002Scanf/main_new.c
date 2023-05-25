#include<stdio.h>

int main(void)
{
	float a1;
	float a2;
	float a3;
	float avg;

	printf("Enter 3 numbers: ");
	scanf("%f %f %f", &a1, &a2, &a3);

	avg = (a1 + a2 + a3) / 3;

	printf("Avg is: %f", avg);
	while(getchar() != '\n'){}
	getchar();

	return 0;
}

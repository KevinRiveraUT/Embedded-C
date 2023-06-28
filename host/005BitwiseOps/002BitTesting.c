#include <stdio.h>
#include <stdint.h>

int main(void){
	int32_t a;

	printf("For the love of all that is holy, please enter a number: ");
	scanf("%d", &a);

	int32_t oddeven = a & 1;

	if (oddeven == 1)
		printf("\nNumber provided is odd.");
	else
		printf("\nNumber provided is even.");


	while(getchar() != '\n'){}
	getchar();

	return 0;
}

#include <stdio.h>
#include <stdint.h>

int main(void){
	int32_t a;

	printf("For the love of all that is holy, please enter a number: ");
	scanf("%d", &a);

	int32_t clearedbitted = a & 72;

	printf("\nNumber provided with bits 4 5 6 cleared is: %d", clearedbitted);


	while(getchar() != '\n'){}
	getchar();

	return 0;
}

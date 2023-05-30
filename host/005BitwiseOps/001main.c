#include <stdio.h>
#include <stdint.h>

int main(void){
	int a, b;

	printf("For the love of all that is holy, please enter two integers: ");
	scanf("%d %d", &a, &b);

	printf("\nBitwise & of a and b are: %d", a&b);
	printf("\nBitwise | of a and b are: %d", a|b);
	printf("\nBitwise ^ of a and b are: %d", a^b);
	printf("\nBitwise ~ of a is: %d", ~a);

	while(getchar() != '\n'){}
	getchar();

	return 0;
}

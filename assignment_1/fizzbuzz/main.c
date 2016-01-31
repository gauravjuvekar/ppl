#include <stdio.h>

int main(void) {
	unsigned int num;
	for (num = 1; num < 101; num++) {
		if ((num % 3) == 0) printf("Fizz");
		if ((num % 5) == 0) printf("Buzz");
		if (((num % 3) == 0) || ((num % 5) == 0)) {
		}
		else {
			printf("%d", num);
		}
		printf("\n");
	}

	return 0;
}

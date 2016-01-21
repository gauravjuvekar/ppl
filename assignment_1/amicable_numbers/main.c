#include <stdio.h>
#include <stdlib.h>

#define UPPER_LIMIT 1000


int sum_divs(int num) {
	int sum = 1;
	int i;

	for (i = 2; i * i < num; i++) {
		if ((num % i) == 0) {
			sum += i;
			sum += (num / i);
		}
	}
	if ((i * i) == num) {
		sum += i;
	}
	return sum;
}


int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;

	int sum_divs_1k[UPPER_LIMIT + 1];
	int i;

	for (i = 0; i < UPPER_LIMIT + 1; i++) {
		sum_divs_1k[i] = sum_divs(i);
	}

	for (i = 0; i < UPPER_LIMIT + 1; i++) {
		if ((sum_divs_1k[i] < UPPER_LIMIT + 1) &&
		    (sum_divs_1k[i] != i) &&
			(sum_divs_1k[sum_divs_1k[i]] == i)) {
			printf("%d, %d\n", i, sum_divs_1k[i]);
		}
		sum_divs_1k[i] = 0;
	}

	return 0;
}

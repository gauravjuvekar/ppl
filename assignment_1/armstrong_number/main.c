#define _ISOC99_SOURCE
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>


unsigned long long int intpow(uint8_t num, long int exponent) {
	unsigned long long int ret = 1;
	while (exponent) {
		if (exponent & 1) ret *= num;
		exponent /= 2;
		num *= num;
	}
	return ret;
}


int main(int argc, char *argv[]) {
	char *endptr;
	char *start = argv[1];
	while (!isdigit(*start)) start++;
	unsigned long long int num = strtol(start, &endptr, 10);
	const unsigned long long int orig_num = num;
	long int len = endptr - start;
	assert(len);

	unsigned long long int powers[10] = {0, 1};
	size_t i;

	for (i = 2; i < 10; i++) {
		powers[i] = intpow(i, len);
	}

	while (*start != '\0') {
		num -= powers[*start - '0'];
		start++;
	}

	printf("%llu is %san Armstrong number\n", orig_num, (num ? "not ": ""));

	return 0;
}

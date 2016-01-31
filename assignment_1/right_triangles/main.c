#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int a;
	int b;
	int c;
	int n = 1000;

	for (a = 1; a < n; a++) {
		for (b = 1; b < a; b++) {
			for (c = 1; c < b; c++) {
				if ((a * a) == ((b * b) + (c * c))) {
					printf("%d %d %d\n", a, b, c);
				}
			}
		}
	}

	return 0;
}

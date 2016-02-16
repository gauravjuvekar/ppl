int f(int num) {
	return ((num ? num * f(num - 1) : 1));
}


int main(void) {
	return f(3);
}

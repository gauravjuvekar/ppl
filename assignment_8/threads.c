#include <pthread.h>
#include <stdio.h>

void *print_world(void *data) {
	(void)data;
	printf("World\n");
	return NULL;
}

void *print_hello(void *data) {
	(void)data;
	printf("Hello\n");
	return NULL;
}

int main() {
	pthread_t world_thread;
	pthread_t hello_thread;

	if(pthread_create(&hello_thread, NULL, print_hello, NULL)) {
		return 1;
	}
	if(pthread_create(&world_thread, NULL, print_world, NULL)) {
		return 1;
	}
	if(pthread_join(hello_thread, NULL)) {
		return 2;
	}
	if(pthread_join(world_thread, NULL)) {
		return 2;
	}
	return 0;
}

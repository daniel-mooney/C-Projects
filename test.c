#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Person {
	char *name;
	int age;
} Person;

int main(void) {

	Person x = {x.name = "steve", x.age = 56};

	printf("Name: %s\t\tAge: %d\n", x.name, x.age);

	Person x = {.name = "craig", .age = 25};

	printf("Name: %s\t\tAge: %d\n", x.name, x.age);

	

}


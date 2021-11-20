#include <stdio.h>
#include <stdlib.h>

void counter(int start, int end, int base);

#define MAX_BUFF 1000

int main(int argc, char **argv) {
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    int base = atoi(argv[3]);

    counter(start, end, base);

    return 0;
}

void counter(int start, int end, int base) {
    int n = start;

    while (n <= end) {
        char number[MAX_BUFF];
        itoa(n, number, base);

        printf("%s\n", number);
        n++;
    }
}


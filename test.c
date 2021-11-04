#include <stdio.h>
#include <math.h>
#include <string.h>

int main() {

    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    

    for (int i = 0; i < 20; i++) {
        a++;
        for (int j = 0; j < 20; j++) {
            b++;
            for (int k = 0; k < 20; k++) {
                c++;
                for (int l = 0; l < 20; l++) {
                    d++;
                    for (int m = 0; m < 20; m++) {
                        e++;
                    }
                }
            }
        }
    }
    

    return 0;
}


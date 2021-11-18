#include <stdio.h>

void hanoi_solver(int N, int from_peg, int aux_peg, int to_peg);
int find_aux_peg(int to_peg, int from_peg);

int main(void){

    printf("Enter the height of the tower, start peg and end peg: ");

    int height, start, end;
    scanf("%d %d %d", &height, &start, &end);

    int aux_peg = find_aux_peg(start, end);

    hanoi_solver(height, start, aux_peg, end);
	
    return 0;
}

void hanoi_solver(int N, int from_peg, int aux_peg, int to_peg) {
    if (N == 1) {
        printf("%d -> %d\n", from_peg, to_peg);
    } else {
        hanoi_solver(N - 1, from_peg, to_peg, aux_peg);
        printf("%d -> %d\n", from_peg, to_peg);
        hanoi_solver(N - 1, aux_peg, from_peg, to_peg);
    }
}

int find_aux_peg(int to_peg, int from_peg) {

    int numbers[] = {1, 2, 3};

    numbers[to_peg - 1] = 0;
    numbers[from_peg - 1] = 0;

    for (int i = 0; i < 3; i++) {
        if (numbers[i] != 0) {
            return numbers[i];
        }
    }
    return -1;
}
#include <stdio.h>

int T, N;
int mem[41][2];

int main(void) {
        mem[0][0] = 1;
        mem[1][1] = 1;
        for(int i = 2; i < 41; i++) {
                mem[i][0] = mem[i-1][0] + mem[i-2][0];
                mem[i][1] = mem[i-1][1] + mem[i-2][1];
        }

        scanf("%d", &T);
        for(int t = 0; t < T; t++) {
                scanf("%d", &N);

                printf("%d %d\n", mem[N][0], mem[N][1]);
        }

        return 0;
}


#include <stdio.h>

int A, B;

int main(void) {
    scanf("%d %d", &A, &B);
    if(A < B) {
        printf("<");
    } else if (A > B) {
        printf(">");
    } else {
        printf("==");
    }
    
    return 0;
}

#include <stdio.h>

int A, B, ans;

int main(void) {
    scanf("%d %d", &A, &B);
    
    printf("%d\n", A * (B%10));
    printf("%d\n", A * ((B/10)%10));
    printf("%d\n", A * ((B/100)%10));
    printf("%d", A * B);
    
    return 0;
}

#include <stdio.h>

int insert_bigger(int A[], int m, int *b, int *count) {
    int data = A[m];
    int i = m-1;
    while (i>=0 && A[i]<data && *b>0) {
        A[i + 1] = A[i];
        (*count)++;
        (*b)--;
        i--;
    }
    A[i + 1] = data;
    return 0;
}

int main() {
    
    int n, b;
    scanf("%d%d", &n, &b);
    int A[n];
    for(int i=0; i<n; i++) {
        scanf("%d", &A[i]);
    }
    
    int count = 0;
    for (int i = 0; i < n; i++) {
        insert_bigger(A, i, &b, &count);
        if (b == 0) {
            break;
        }
    }

    printf("The array is ");
    for (int i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("after %d back-moves.\n", count);

    return 0;    
}
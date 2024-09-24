#include<stdio.h>
int main(){
    int n, i, j;
    printf("Enter the number of lines for the triangle: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
        for(j=0; j<i; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
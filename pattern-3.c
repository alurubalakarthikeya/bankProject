#include<stdio.h>
int main(){
    int n, i, j, k;
    printf("Enter the number of rows: ");
    scanf("%d", &n);
    
    for(i=1; i<=n; i++){
        for(k=2*i-1; k<=0; k++){
            printf("*");
        }
        for(j=1; j<=n-i; j++){
            printf(" ");
        }
        printf("\n");
    }
}
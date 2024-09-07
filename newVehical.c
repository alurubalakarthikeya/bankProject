#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool verify();
int main(){
    char regNo[10];
    printf("Enter the registration number: ");
    scanf("%s", regNo);
    if(verify(regNo)){
        printf("Accepted, Valid Registration Number\n");
    } else {
        printf("Rejected, Invalid Registration Number\n");
    }
}

bool verify(char regNo[]){
    if(strlen(regNo)!=10){
        printf("Invalid registration number, enter a valid registration number!\n");
        return false;
    }
    for(int i=0; i<2; i++){
        if(!isalpha(regNo[i])){
            return false;
        }
    }
    for(int i=2; i<4; i++){
        if(!isdigit(regNo[i])){
            return false;
        }
    }
    for(int i=4; i<6; i++){
        if(!isalpha(regNo[i])){
            return false;
        }
    }
    for(int i=6; i<10; i++){
        if(!isdigit(regNo[i])){
            return false;
        }
    }
    return true;
}
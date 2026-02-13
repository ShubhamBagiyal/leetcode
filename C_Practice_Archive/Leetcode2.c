//PALINDROM WITH PREVENTING OVERFLOW (revese VALUE MORE THAN INTMAX-digit/10)
#include<stdio.h>
#include <stdbool.h>
#include <limits.h>  // Required for INT_MAX

bool isPalindrome(int x){
    if(x<0 || (x%10==0 && x!=0) )   //x cant be -ve and multipleof 10
        return false;
    int reversed=0;
    int original=x;
    while(x>0){
        int digit= x%10;
        if(reversed==(INT_MAX-digit)/10){
            return false;
        }
        reversed=reversed*10+digit;
        x/=10;
    }
    return reversed==original;
}
int main(){
    int x;
    printf("ENTER A NUMBER TO CHECK : ");
    scanf("%d",&x);
    if(isPalindrome(x)){
        printf("THE NUMBER %d IS PALINDROM",x);
    }
    else{
        printf("THE NUMBER %d IS NOT PALINDROM",x);
    }
}

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    for(int i = digitsSize-1 ; i>=0 ; i--){
        if(digits[i]==9){
            digits[i]=0;    //if digit is 9 put 0
        }
        else{
            digits[i]++;
            *returnSize=digitsSize;
            return digits;
        }
    }
    //if all digits are 9 (eg 999->1000)
    //mallocate memory with digitsSize+1
    int*newdigits=(int*)malloc(digitsSize+1*(sizeof(int)));
    newdigits[0]=1;
    for(int i=1;i<digitsSize;i++){
        newdigits[i]=0;
    }
    *returnSize=digitsSize+1;
    return newdigits;
}

int main() {
    int digits[] = {1,9,9,9};  // Example input
    int digitsSize = sizeof(digits) / sizeof(digits[0]);
    int returnSize;

    int* result = plusOne(digits, digitsSize, &returnSize);

    printf("Result: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", result[i]);
    }
    printf("\n");

    return 0;
}

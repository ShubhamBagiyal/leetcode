#include <stdio.h>
#include <string.h>

int romanToInt(char *s) {
    int total = 0, prev = 0, curr;

    for(int i=strlen(s)-1;i>=0;i--){
        switch(s[i]){
            case 'I' : curr = 1 ; break ;
            case 'V' : curr = 5 ; break ;
            case 'X' : curr = 10 ; break ;
            case 'L' : curr = 50 ; break ;
            case 'C' : curr = 100 ; break ;
            case 'D' : curr = 500 ; break ;
            case 'M' : curr = 1000 ; break ;
            default : return -1;
        }
        if(curr<prev){
            total-=curr;
        }
        else{
            total+=curr;
        }
        prev=curr;
    }
    return total;
}

int main() {
    char roman[20];
    printf("Enter a Roman numeral: ");
    scanf("%s", roman);

    int result = romanToInt(roman);
    if (result == -1) {
        printf("Invalid Roman numeral!\n");
    } else {
        printf("Integer value: %d\n", result);
    }

    return 0;
}

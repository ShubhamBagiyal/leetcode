#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    int k=1;
    for(int i=1;i<numsSize;i++){
        if(nums[i]!=nums[k-1]){
            nums[k]=nums[i];
            k++;
        }
    }return k;
}
int main() {
    int nums[] = {1, 1, 2, 2, 3, 4, 4, 5};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates(nums, numsSize);

    printf("Unique count: %d\n", k);
    printf("Updated array: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

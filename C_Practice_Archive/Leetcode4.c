#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;  // Counter for new array length

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {  
            nums[k] = nums[i];  // Move valid elements forward
            k++;
        }
    }
    return k;  // Return the new size of the array
}

int main() {
    int nums[] = {3, 2, 2, 3};  
    int val = 3;
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int newLength = removeElement(nums, numsSize, val);

    // Print the modified array
    printf("Modified array: ");
    for (int i = 0; i < newLength; i++) {
        printf("%d ", nums[i]);
    }
    printf("\nNew length: %d\n", newLength);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* arr = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                arr[0] = i;
                arr[1] = j;
                *returnSize = 2; // Set the return size
                return arr; // Return immediately when found
            }
        }
    } 
    free(arr); // Free memory if no solution is found
    *returnSize = 0; // Indicate no solution found
    return NULL;
}

// Driver code to test the function
int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    
    int* result = twoSum(nums, 4, target, &returnSize);
    
    if (result) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result); // Don't forget to free allocated memory
    } else {
        printf("No solution found\n");
    }

    return 0;
}

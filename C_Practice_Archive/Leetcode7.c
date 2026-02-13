#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0], count = 1;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }
    return candidate;
}

// Example Usage
int main() {
    int nums[] = {3, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    printf("Majority Element: %d\n", majorityElement(nums, size)); // Output: 3
    return 0;
}

// LeetCode 75 - Sort Colors
// Dutch National Flag Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        int low = 0;
        int mid = 0;
        int high = n - 1;

        while (mid <= high) {

            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if (nums[mid] == 1) {
                mid++;
            }

            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

void printArray(vector<int>& nums) {
    for (int x : nums)
        cout << x << " ";
    cout << endl;
}

int main() {

    Solution sol;

    vector<int> nums = {2,0,2,1,1,0};

    cout << "Original array: ";
    printArray(nums);

    sol.sortColors(nums);

    cout << "Sorted array: ";
    printArray(nums);

    return 0;
}

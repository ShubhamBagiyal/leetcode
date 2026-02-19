// LeetCode 169. Majority Element (Boyer-Moore Voting Algorithm)
#include <iostream>
#include <vector>
using namespace std;

int majorityElement(vector<int>& nums) {
    int count = 1;
    int candidate = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == candidate) {
            count++;
        }
        else {
            count--;
        }

        if(count == 0) {
            candidate = nums[i];
            count = 1;
        }
    }

    return candidate;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    int result = majorityElement(nums);

    cout << "Majority Element: " << result << endl;

    return 0;
}

// 189. Rotate Array

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    obj.rotate(nums, k);

    cout << "Rotated array: ";
    for(int num : nums){
        cout << num << " ";
    }

    return 0;
}
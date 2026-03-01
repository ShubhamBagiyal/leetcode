// LeetCode 540
// Single Element in a Sorted Array
// Binary Search | O(log n)

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int n = nums.size();

        if(n == 1)
            return nums[0];

        int str = 0;
        int end = n - 1;

        while(str <= end){

            int mid = (str + end) / 2;

            // check first element
            if(mid == 0 && nums[0] != nums[1])
                return nums[0];

            // check last element
            if(mid == n - 1 && nums[n - 1] != nums[n - 2])
                return nums[n - 1];

            // check if mid itself is single
            if(mid > 0 && mid < n - 1 &&
               nums[mid] != nums[mid-1] &&
               nums[mid] != nums[mid+1])
                return nums[mid];

            // binary search logic
            if(mid % 2 == 0){
                if(nums[mid] == nums[mid+1])
                    str = mid + 1;
                else
                    end = mid - 1;
            }
            else{
                if(nums[mid] == nums[mid-1])
                    str = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return -1;
    }
};

int main(){

    Solution sol;

    vector<int> nums = {1,1,2,2,3,4,4,5,5};

    cout << "Single element: "
         << sol.singleNonDuplicate(nums) << endl;

    return 0;
}

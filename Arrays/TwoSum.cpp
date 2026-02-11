// 1.Two Sum

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){

                if(nums[i] + nums[j] == target){

                    vector<int> result(2);
                    result[0] = i;
                    result[1] = j;

                    return result;
                }
            }
        }

        return {};
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

    int target;
    cout << "Enter target: ";
    cin >> target;

    Solution obj;
    vector<int> answer = obj.twoSum(nums, target);

    if(answer.empty()){
        cout << "No valid pair found." << endl;
    }
    else{
        cout << "Indices: " << answer[0] << " " << answer[1] << endl;
    }

    return 0;
}

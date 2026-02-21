// 238. Product of Array Except Self
// Optimal prefix-suffix approach (O(n) time, O(1) extra space except output)

#include <iostream>
#include <vector>
using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);

    // prefix pass
    int prefix = 1;
    for(int i = 0; i < n; i++){
        result[i] = prefix;
        prefix *= nums[i];
    }

    // suffix pass
    int suffix = 1;
    for(int i = n-1; i >= 0; i--){
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    vector<int> result = productExceptSelf(nums);

    cout << "Result: ";
    for(int x : result)
        cout << x << " ";

    return 0;
}

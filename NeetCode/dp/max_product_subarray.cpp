#include <climits> // for INT_MIN
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = nums[0];
        int curMin = 1;
        int curMax = 1;
        for(int i = 0; i < nums.size(); i++ ) {
            int tmp = curMin * nums[i];
            int tmp2 = curMax * nums[i]; 
            curMin = min(min(tmp,tmp2), nums[i]);
            curMax = max(max(tmp,tmp2), nums[i]);
            res = max(res, curMax);
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example usage:
    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Max product of {2, 3, -2, 4}: " << sol.maxProduct(nums1) << endl;

    vector<int> nums2 = {-2, 0, -1};
    cout << "Max product of {-2, 0, -1}: " << sol.maxProduct(nums2) << endl;

    vector<int> nums3 = {-2, 3, -4};
    cout << "Max product of {-2, 3, -4}: " << sol.maxProduct(nums3) << endl;

    return 0;
}
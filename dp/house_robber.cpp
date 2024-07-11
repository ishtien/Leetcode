#include <iostream>
#include <vector>

using namespace std;

class SolutionModify {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        int first = 0;
        int second = 0;
        int result = 0;
        for(int i = 0; i < sz; i++) {
            result = max( second, first + nums[i]);
            first = second;
            second = result;
        }
        return result;
        
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        vector<int> target(sz, 0);
        
        if (sz == 1) return nums[0];
        if (sz == 2) return max(nums[0], nums[1]);
        
        target[0] = nums[0];
        target[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < sz; i++) {
            target[i] = max(target[i - 1], target[i - 2] + nums[i]);
        }
        
        return target[sz - 1];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {2, 7, 9, 3, 1};
    
    cout << "Maximum amount that can be robbed from nums1: " << sol.rob(nums1) << endl;
    cout << "Maximum amount that can be robbed from nums2: " << sol.rob(nums2) << endl;

    return 0;
}

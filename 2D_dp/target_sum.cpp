#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // DP[index, total] = ways
        unordered_map<long, int> dp;
        return backtrack(0, 0, dp, nums, target);
    }
    
    int backtrack(int index, int sum, unordered_map<long, int> &dp, vector<int>& nums, int target) {
        if (index == nums.size()) {
            return (sum == target) ? 1 : 0;
        }
        
        long key = static_cast<long>(index) << 32 | (sum & 0xffffffffL);
        if (dp.find(key) != dp.end()) return dp[key];

        dp[key] = backtrack(index + 1, sum + nums[index], dp, nums, target) + 
                  backtrack(index + 1, sum - nums[index], dp, nums, target);
        return dp[key];
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    cout << "Test case 1: " << solution.findTargetSumWays(nums1, target1) << endl;

    // Test case 2
    vector<int> nums2 = {1};
    int target2 = 1;
    cout << "Test case 2: " << solution.findTargetSumWays(nums2, target2) << endl;

    // Test case 3
    vector<int> nums3 = {1, 2, 3};
    int target3 = 4;
    cout << "Test case 3: " << solution.findTargetSumWays(nums3, target3) << endl;

    // Test case 4
    vector<int> nums4 = {2, 5, 1};
    int target4 = 3;
    cout << "Test case 4: " << solution.findTargetSumWays(nums4, target4) << endl;

    return 0;
}

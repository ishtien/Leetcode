#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;
        for(int i = 1; i < nums.size(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        } 
        return res;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of the Longest Increasing Subsequence in {10, 9, 2, 5, 3, 7, 101, 18}: " << sol.lengthOfLIS(nums1) << endl;

    // Example 2
    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Length of the Longest Increasing Subsequence in {0, 1, 0, 3, 2, 3}: " << sol.lengthOfLIS(nums2) << endl;

    // Example 3
    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Length of the Longest Increasing Subsequence in {7, 7, 7, 7, 7, 7, 7}: " << sol.lengthOfLIS(nums3) << endl;

    return 0;
}

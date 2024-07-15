#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm> // for find
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto & n : nums) {
            sum += n;
        }
        if(sum % 2 != 0) return false;
        int target = sum / 2;
        unordered_set<int> dp;
        dp.insert(0);
        for(int i = 0; i < nums.size(); i++) {
            unordered_set<int> nextDP;
            for(auto &item : dp) {
                nextDP.insert(nums[i] + item);
                nextDP.insert(item);
            }
            dp = nextDP;
        }
        auto it = find(dp.begin(), dp.end(), target);
        return (it != dp.end());
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {1, 5, 11, 5};
    cout << "Can partition {1, 5, 11, 5}? " << (sol.canPartition(nums1) ? "Yes" : "No") << endl;

    // Example 2
    vector<int> nums2 = {1, 2, 3, 5};
    cout << "Can partition {1, 2, 3, 5}? " << (sol.canPartition(nums2) ? "Yes" : "No") << endl;

    // Example 3
    vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Can partition {1, 2, 3, 4, 5, 6, 7}? " << (sol.canPartition(nums3) ? "Yes" : "No") << endl;

    return 0;
}

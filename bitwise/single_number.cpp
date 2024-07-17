#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {2, 2, 1};
    cout << "Single number in nums1: " << sol.singleNumber(nums1) << endl; // Output: Single number in nums1: 1

    // Test case 2
    vector<int> nums2 = {4, 1, 2, 1, 2};
    cout << "Single number in nums2: " << sol.singleNumber(nums2) << endl; // Output: Single number in nums2: 4

    // Test case 3
    vector<int> nums3 = {1};
    cout << "Single number in nums3: " << sol.singleNumber(nums3) << endl; // Output: Single number in nums3: 1

    // Test case 4
    vector<int> nums4 = {1, 1, 2, 2, 3};
    cout << "Single number in nums4: " << sol.singleNumber(nums4) << endl; // Output: Single number in nums4: 3

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

using namespace std;

class Solution {
public:
    int findDuplicateLinklist(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        int res = 0;
        while(true) {
            res = nums[res];
            slow = nums[slow];
            if(res == slow) return slow;
        }
        return -1;

    }
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                return nums[i];
            }
        }
        return -1;
    }
};

int main() {
    // Example usage of Solution class
    Solution solution;

    // Test case 1: nums = {1, 3, 4, 2, 2}
    vector<int> nums1 = {1, 3, 4, 2, 2};
    int result1 = solution.findDuplicateLinklist(nums1);
    cout << "Duplicate number in nums1: " << result1 << endl;

    // Test case 2: nums = {3, 1, 3, 4, 2}
    vector<int> nums2 = {3, 1, 3, 4, 2};
    int result2 = solution.findDuplicateLinklist(nums2);
    cout << "Duplicate number in nums2: " << result2 << endl;

    // Test case 3: nums = {1, 1}
    vector<int> nums3 = {1, 1};
    int result3 = solution.findDuplicate(nums3);
    cout << "Duplicate number in nums3: " << result3 << endl;

    // Test case 4: nums = {1, 2, 3, 4}
    vector<int> nums4 = {1, 2, 3, 4};
    int result4 = solution.findDuplicate(nums4);
    cout << "Duplicate number in nums4: " << result4 << endl;

    return 0;
}
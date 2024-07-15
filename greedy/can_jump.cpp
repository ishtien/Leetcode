#include <iostream>
#include <vector>
using namespace std;

class SolutionModify {
public:
    bool canJump(std::vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0; // Track the farthest reachable index

        for (int i = 0; i < n; ++i) {
            if (i > maxReach) {
                return false; // If current index is beyond the farthest reachable index
            }
            maxReach = std::max(maxReach, i + nums[i]); // Update the farthest reachable index
            if (maxReach >= n - 1) {
                return true; // If we can reach or surpass the last index
            }
        }

        return false; // If we exit the loop without reaching the last index
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return true;
        int idx = 0;
        while(idx < nums.size()-1) {
            if(nums[idx] == 0) return false;
            idx = idx + nums[idx];
        }
        return true;
    }
};

// Function to print the result
void printResult(bool result) {
    std::cout << (result ? "Can jump to the last index" : "Cannot jump to the last index") << std::endl;
}

int main() {
    Solution solution;

    // Define some test cases
    std::vector<int> nums1 = {2, 3, 1, 1, 4}; // Expected output: true
    std::vector<int> nums2 = {3, 2, 1, 0, 4}; // Expected output: false
    std::vector<int> nums3 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Expected output: true

    // Call the canJump function for each test case
    bool result1 = solution.canJump(nums1);
    bool result2 = solution.canJump(nums2);
    bool result3 = solution.canJump(nums3);

    // Print the results
    std::cout << "Test case 1: ";
    printResult(result1);
    std::cout << "Test case 2: ";
    printResult(result2);
    std::cout << "Test case 3: ";
    printResult(result3);

    return 0;
}

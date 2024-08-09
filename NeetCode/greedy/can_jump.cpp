#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty()) return 0;
        int reachDistance = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            if(reachDistance < i) return false;
            reachDistance = max(reachDistance, i + nums[i]);
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

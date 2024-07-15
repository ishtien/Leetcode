#include <iostream>
#include <vector>
#include <algorithm> // for std::max

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int res = nums[0];
        int curSum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            curSum = max(curSum + nums[i], nums[i]);
            res = max(res, curSum);
        }
        return res;
    }
};

// Function to print the result
void printResult(int result) {
    std::cout << "Maximum subarray sum: " << result << std::endl;
}

int main() {
    Solution solution;

    // Define some test cases
    std::vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::vector<int> nums2 = {1};
    std::vector<int> nums3 = {5, 4, -1, 7, 8};

    // Call the maxSubArray function for each test case
    int result1 = solution.maxSubArray(nums1);
    int result2 = solution.maxSubArray(nums2);
    int result3 = solution.maxSubArray(nums3);

    // Print the results
    std::cout << "Test case 1: ";
    printResult(result1);
    std::cout << "Test case 2: ";
    printResult(result2);
    std::cout << "Test case 3: ";
    printResult(result3);

    return 0;
}

#include <iostream>
#include <vector>
#include <numeric> // for accumulate
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sz = nums.size();
        int target_sum = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < sz + 1; i++) {
            sum += i;
        }
        return sum - target_sum;
    }
};

class SolutionModify {
public:
    int missingNumber(vector<int>& nums) {
        int sz = nums.size();
        int res = 0;
        for(int i = 0; i < sz + 1; i++) {
            if(i == sz) res^=i;
            else {
                res ^=i;
                res^=nums[i];
            }
        }
        return res;
    }
};


int main() {
    Solution sol;

    // Test case 1
    vector<int> nums1 = {3, 0, 1};
    int missing1 = sol.missingNumber(nums1);
    cout << "Missing number in nums1: " << missing1 << endl; // Output: Missing number in nums1: 2

    // Test case 2
    vector<int> nums2 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    int missing2 = sol.missingNumber(nums2);
    cout << "Missing number in nums2: " << missing2 << endl; // Output: Missing number in nums2: 8

    // Test case 3
    vector<int> nums3 = {0};
    int missing3 = sol.missingNumber(nums3);
    cout << "Missing number in nums3: " << missing3 << endl; // Output: Missing number in nums3: 1

    // Test case 4
    vector<int> nums4 = {1};
    int missing4 = sol.missingNumber(nums4);
    cout << "Missing number in nums4: " << missing4 << endl; // Output: Missing number in nums4: 0

    return 0;
}

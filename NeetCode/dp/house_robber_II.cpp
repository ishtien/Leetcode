#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1) return nums[0];
        vector<int> sub1(nums.begin(), nums.begin() + sz - 1);
        vector<int> sub2(nums.begin() + 1, nums.begin() + sz);
        int rob1 = rob_wo_circle(sub1);
        int rob2 = rob_wo_circle(sub2);
        return max(rob1, rob2);
    }

    int rob_wo_circle(vector<int>& nums) {
        int first = 0;
        int second = 0;
        int sz = nums.size();
        int result = 0;
        for(int i = 0; i < sz; i++) {
            result = max(first + nums[i], second);
            first = second;
            second = result;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2, 3, 2};
    vector<int> nums2 = {1, 2, 3, 1};
    
    cout << "Max amount you can rob (without circle): " << sol.rob_wo_circle(nums1) << endl;
    cout << "Max amount you can rob (without circle): " << sol.rob_wo_circle(nums2) << endl;
    
    cout << "Max amount you can rob (with circle): " << sol.rob(nums1) << endl;
    cout << "Max amount you can rob (with circle): " << sol.rob(nums2) << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.empty()) return 0;
        int l = 0;
        int r = 0;
        int res = 0;
        while(r < nums.size()-1) {
            int maxDistance = 0;
            for(int i = l ; i <= r; i++) {
                maxDistance = max(maxDistance, i + nums[i]);          
            }
            l = r + 1;
            r = maxDistance;
            res++;
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    vector<int> nums1 = {2, 3, 1, 1, 4};
    vector<int> nums2 = {3, 2, 1, 0, 4};
    
    cout << "Minimum jumps required for nums1: " << sol.jump(nums1) << endl;
    cout << "Minimum jumps required for nums2: " << sol.jump(nums2) << endl;
    
    return 0;
}

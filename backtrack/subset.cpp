#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;
        helper(0, nums, cur, res);
        return res;
    }

    void helper(int idx, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        if(idx >= nums.size()) {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[idx]);
        helper(idx + 1, nums, cur, res);
        cur.pop_back();
        helper(idx + 1, nums, cur, res);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> subsets = sol.subsets(nums);

    // Printing the subsets
    cout << "Subsets of {1, 2, 3} are:" << endl;
    for (const auto& subset : subsets) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

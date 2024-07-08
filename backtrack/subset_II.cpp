#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());
        helper(0, nums, cur, res);  
        return res; 
    }
    void helper(int idx, vector<int>& nums, vector<int>& cur, vector<vector<int>>& res) {
        if(idx ==nums.size()) {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[idx]);
        helper(idx + 1, nums, cur, res);
        while (idx + 1 < nums.size() && nums[idx+1] == nums[idx]) {
            idx +=1; 
        }
        cur.pop_back();
        helper(idx + 1, nums, cur, res);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 2}; // Example input

    vector<vector<int>> result = sol.subsetsWithDup(nums);

    // Print the result
    cout << "Subsets with duplicates removed:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

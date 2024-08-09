#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> // For max function

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        unordered_map<long, int> cache; // <l + r, coins>
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return dfs(nums, cache, 1, nums.size()-2);
    }

    int dfs(vector<int> & nums, unordered_map<long, int> &cache, int l, int r) {
        long key = static_cast<long>(l) << 32 | r;
        if(l > r) return 0;
        if(cache.find(key) != cache.end()) return cache[key];
        int coins = 0;
        for(int i = l; i <= r; i++) {
            coins = nums[l-1] * nums[i] * nums[r+1];
            coins += dfs(nums, cache, l, i-1) + dfs(nums, cache, i + 1, r);
            cache[key] = max(cache[key], coins);
        }
        return cache[key];
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {3, 1, 5, 8};
    cout << "Test case 1: " << solution.maxCoins(nums1) << endl;

    // Test case 2
    vector<int> nums2 = {1, 5};
    cout << "Test case 2: " << solution.maxCoins(nums2) << endl;

    // Test case 3
    vector<int> nums3 = {9, 8, 7, 6, 5, 1, 2, 3, 4};
    cout << "Test case 3: " << solution.maxCoins(nums3) << endl;

    // Test case 4
    vector<int> nums4 = {1};
    cout << "Test case 4: " << solution.maxCoins(nums4) << endl;

    return 0;
}

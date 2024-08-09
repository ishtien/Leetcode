#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        unordered_map<long, int> dp;
        return dfs(0, true, dp, prices);
    }

    int dfs(int i, bool buying, unordered_map<long, int>& dp, vector<int>& prices) {
        if (i >= prices.size()) {
            return 0;
        }

        long key = (static_cast<long>(i) << 1) | (buying ? 1 : 0);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int cooldown = dfs(i + 1, buying, dp, prices);
        if (buying) {
            int buy = dfs(i + 1, false, dp, prices) - prices[i];
            dp[key] = max(buy, cooldown);
        } else {
            int sell = dfs(i + 2, true, dp, prices) + prices[i];
            dp[key] = max(sell, cooldown);
        }
        return dp[key];
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}

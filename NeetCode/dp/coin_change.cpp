#include <iostream>
#include <vector>
#include <climits> // for INT_MAX
#include <algorithm> // for std::min

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        // for(auto & coin : coins) {
        //     if(coin >=0 && coin < amount)
        //         dp[coin] = 1;
        // }
        for(int i = 0; i <=amount; i++) {
            for(auto & coin : coins) {
                if(i - coin >= 0 && i <= amount && dp[i-coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i-coin] + 1); 
                }
            }
        }
        return (dp[amount]==INT_MAX)?-1:dp[amount];
    }
};

int main() {
    Solution sol;

    // Test cases
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Coins: [1, 2, 5], Amount: " << amount1 << " => Minimum coins needed: " << sol.coinChange(coins1, amount1) << endl;

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Coins: [2], Amount: " << amount2 << " => Minimum coins needed: " << sol.coinChange(coins2, amount2) << endl;

    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Coins: [1], Amount: " << amount3 << " => Minimum coins needed: " << sol.coinChange(coins3, amount3) << endl;

    vector<int> coins4 = {1};
    int amount4 = 2;
    cout << "Coins: [1], Amount: " << amount4 << " => Minimum coins needed: " << sol.coinChange(coins4, amount4) << endl;

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int sz = coins.size();
        vector<vector<int>> cache(sz, vector<int>(amount + 1, 0));
        for(int i = 0; i < sz; i++) {
            cache[i][amount] = 1;
        }
        for(int i = sz - 1; i>=0; i--) {
            for(int j = amount - 1 ; j >=0; j--) {
                if(cache[i][j] != 0) continue;
                if(j + coins[i] <= amount) {
                    cache[i][j] += cache[i][j + coins[i]];
                }
                if(i < sz-1) {
                    cache[i][j] += cache[i+1][j];
                }
            }
        }
        
        return cache[0][0];
    }
};


int main() {
    Solution sol;
    
    // Test cases
    vector<int> coins1 = {1, 2, 5};
    int amount1 = 5;
    cout << "Number of ways to make amount " << amount1 << " with coins {1, 2, 5}: " << sol.change(amount1, coins1) << endl; // Output: 4

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Number of ways to make amount " << amount2 << " with coins {2}: " << sol.change(amount2, coins2) << endl; // Output: 0

    vector<int> coins3 = {1};
    int amount3 = 0;
    cout << "Number of ways to make amount " << amount3 << " with coins {1}: " << sol.change(amount3, coins3) << endl; // Output: 1

    vector<int> coins4 = {1, 2, 3};
    int amount4 = 4;
    cout << "Number of ways to make amount " << amount4 << " with coins {1, 2, 3}: " << sol.change(amount4, coins4) << endl; // Output: 4
    
    return 0;
}

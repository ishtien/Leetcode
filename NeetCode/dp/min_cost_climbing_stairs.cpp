#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int sz = cost.size();
        if(cost.size()==2) return cost[0];
        if(cost.size()==3) return min(cost[0], cost[1]);
        for(int i = 2; i < cost.size(); i++) {
            cost[i] += min(cost[i-1], cost[i-2]);
        }
        return cost[sz-1];
    }
};

int main() {
    Solution sol;
    vector<int> cost1 = {1, 2, 3};
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    cout << "Minimum cost for cost1: " << sol.minCostClimbingStairs(cost1) << endl;
    cout << "Minimum cost for cost2: " << sol.minCostClimbingStairs(cost2) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> idx_check;
        for (int i = 0; i < triplets.size(); i++) {
            if (triplets[i][0] > target[0] || triplets[i][1] > target[1] || triplets[i][2] > target[2])
                continue;
            for (int j = 0; j < target.size(); j++) {
                if (target[j] == triplets[i][j]) {
                    idx_check.insert(j);
                }
            }
        }
        return idx_check.size() == 3;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> triplets1 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    vector<int> target1 = {3, 3, 3};
    cout << "Can merge triplets: " << sol.mergeTriplets(triplets1, target1) << endl; // Output: 1 (true)

    // Test case 2
    vector<vector<int>> triplets2 = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}};
    vector<int> target2 = {2, 2, 2};
    cout << "Can merge triplets: " << sol.mergeTriplets(triplets2, target2) << endl; // Output: 0 (false)

    return 0;
}

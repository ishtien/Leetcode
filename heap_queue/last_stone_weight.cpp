#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int i = 0; i < stones.size(); i++) {
            q.push(stones[i]);
        }
        while(q.size() > 1) {
            int first = q.top();
            q.pop();
            int second = q.top();
            q.pop();
            if(first != second) {
                q.push(first - second);
            }
        }
        return (q.empty()) ? 0 : q.top();
    }
};

int main() {
    Solution solution;
    
    vector<int> stones1 = {2, 7, 4, 1, 8, 1};
    cout << "Last stone weight: " << solution.lastStoneWeight(stones1) << endl; // Expected output: 1
    
    vector<int> stones2 = {5, 5, 5, 5, 5};
    cout << "Last stone weight: " << solution.lastStoneWeight(stones2) << endl; // Expected output: 0
    
    vector<int> stones3 = {10};
    cout << "Last stone weight: " << solution.lastStoneWeight(stones3) << endl; // Expected output: 10
    
    return 0;
}

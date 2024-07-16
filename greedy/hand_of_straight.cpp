#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0 ) return false;
        unordered_map<int, int> hmap;
        for(auto &h : hand) {
            hmap[h]++;
        }
        priority_queue<int, vector<int>, greater<int>> minheap;

        for(auto &h : hmap) {
            minheap.push(h.first);
        }
        while(!minheap.empty()) {
            auto top = minheap.top();
            for(int i = 0; i < groupSize ;i++) {

                if(hmap.find(top + i)==hmap.end()) {
                    return false;
                } 
                hmap[top + i]--;
                if(hmap[top + i]==0){
                    if(minheap.top() != top + i) {
                        return false;
                    }
                    minheap.pop();
                } 
            }
        }
        return true;
    }
};


int main() {
    Solution sol;
    
    // Test case 1
    vector<int> hand1 = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize1 = 3;
    cout << "Can form straight hand: " << sol.isNStraightHand(hand1, groupSize1) << endl; // Output: 1 (true)
    
    // Test case 2
    vector<int> hand2 = {1, 2, 3, 4, 5};
    int groupSize2 = 4;
    cout << "Can form straight hand: " << sol.isNStraightHand(hand2, groupSize2) << endl; // Output: 0 (false)
    
    return 0;
}

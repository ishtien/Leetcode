#include <iostream>
#include <vector>
#include <queue> // Include for priority_queue
using namespace std;

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    int kth = 0;
    KthLargest(int k, vector<int>& nums) {
        for(int i =0; i < nums.size(); i++) {
            q.push(nums[i]);
            while(q.size()>k) {
                q.pop();
            }
        }
        kth = k;
    }
    
    int add(int val) {
        q.push(val);
        while(q.size()> kth) q.pop();
        return q.top();
    }
};

int main() {
    vector<int> nums = {4, 5, 8, 2};
    KthLargest k(3, nums); // Initialize KthLargest object with k = 3 and nums = {4, 5, 8, 2}
    
    cout << "Initial KthLargest: " << k.add(3) << endl; // Expected output: 4
    cout << "Add 3: " << k.add(3) << endl; // Expected output: 4
    cout << "Add 5: " << k.add(5) << endl; // Expected output: 5
    cout << "Add 10: " << k.add(10) << endl; // Expected output: 5
    cout << "Add 9: " << k.add(9) << endl; // Expected output: 8
    
    return 0;
}

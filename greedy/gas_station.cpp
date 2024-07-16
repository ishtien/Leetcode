/*
Explanation by 
@arpanbanejee5143

I will try to explain it in my own way-- please be patient and read it, hope you will get the intuition behind the algorithm.

There are 4 parts to it-



Part 1- sum of gas array>=sum of cost array---> 

very intuitive, we should always have enough gas.

Part 2- we are keeping a total+=gas[i]-cost[i] for each i, and whenever it is <0 we are skipping that point and moving forward, making total 0--->

 It means we ran out of gas if we started at some point which was <= current pos of i, so now we have to find a new starting position,

which wall be > curr pos of i.

Now think, why will this new start lie ahead of curr pos i, not anywhere before it,  you could think, we started from point A------>B(total till +ve)------->C(total<0), as per this algo we try to find start ahead of C, what if we started from B and skipped A instead, well that won't work, You moved from A--------> B with some positive value(or 0), or else you would have stopped right at B and made total to 0. So add A improved our chances of having a positive total, so there is no point in looking for the new position start anywhere behind point C.

Part 3- When the total stays +ve, we dn't do anything to the start point, our start pointer points to the first index when our total became positive.

Again this is similar to the above explanation-l

ets suppose we start from X(-ve)--->Y(-ve)--->A(+ve)---->B(+ve)---->C(+ve), where C is the end of the array, our start(which is also the ans) would be A.

Why not B? why not C?

It is because we moved from A to B with some +ve value or atleast 0, whereas if we started from B we would have had only the value of B so earlier point added some value to our total, so its more favorable to help us reach the ans, hence earliest point is always better.

Part 4-- Why we just stop at point C and don t complete the cycle and check.

It is because from Part 1 we would have already identified that if the given set of inputs will have an ans, so if we have reached to Part 3 it means we surely have an ans, and it is mentioned in the question that there is only one valid ans, so we will always choose the most favorable ans-- which is also the fundamental idea of Greedy Algorithims. There is also a mathematical proof for this, that if we got a start point given our total gas >=total cost , we will be able to reach back to that point with just enough gas. 
*/
#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0;
        int total = 0;
        // Check if total gas is sufficient to cover total cost
        if(accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;
        
        for(int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            if(total < 0) {
                total = 0;
                res = i + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> gas1 = {1, 2, 3, 4, 5};
    vector<int> cost1 = {3, 4, 5, 1, 2};
    cout << "Starting point: " << sol.canCompleteCircuit(gas1, cost1) << endl;

    // Test case 2
    vector<int> gas2 = {2, 3, 4};
    vector<int> cost2 = {3, 4, 3};
    cout << "Starting point: " << sol.canCompleteCircuit(gas2, cost2) << endl;

    return 0;
}


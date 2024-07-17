#include <iostream>
#include <vector>
using namespace std;

//This method is n^2 which is not efficient.
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> output;
        for (int i = 0; i <= n; i++) {
            int tmp = i;
            int res = 0;
            while (tmp != 0) {
                tmp = tmp & (tmp - 1);
                res++;
            }
            output.push_back(res);
        }
        return output;
    }
};

class SolutionModidy {
public:
    vector<int> countBits(int n) {
        // 0   0000 dp[0] = 0
        // 1   0001 dp[1] = 1 = 1 + dp[n-1]     
        // 2   0010 dp[2] = 1 = 1 + dp[n-2] *
        // 3   0011 dp[3] = 2 = 1 + dp[n-2]
        // 4   0100 dp[4] = 1 = 1 + dp[n-4] *
        // 5   0101 dp[5] = 2 = 1 + dp[n-4]
        // 6   0110 dp[6] = 2 = 1 + dp[n-4]
        // 7   0111 dp[7] = 3 = 1 + dp[n-4]
        // 8   1000 dp[8] = 1 = 1 + dp[n-8] *
        vector<int> dp(n+1);
        dp[0] = 0;
        int offset = 1;
        for(int i = 1; i <= n; i++) {
            if(i % (offset*2) == 0) offset*=2; // it could be written as if(offset * 2 == i) offset = i;
            dp[i] = 1 + dp[i - offset];
        }
        return dp;
    }
};


int main() {
    SolutionModidy sol;

    // Test case 1
    int n1 = 5;
    vector<int> result1 = sol.countBits(n1);
    cout << "Number of bits for numbers from 0 to " << n1 << ":" << endl;
    for (int i = 0; i <= n1; i++) {
        cout << result1[i] << " ";
    }
    cout << endl; // Output: 0 1 1 2 1 2

    // Test case 2
    int n2 = 10;
    vector<int> result2 = sol.countBits(n2);
    cout << "Number of bits for numbers from 0 to " << n2 << ":" << endl;
    for (int i = 0; i <= n2; i++) {
        cout << result2[i] << " ";
    }
    cout << endl; // Output: 0 1 1 2 1 2 2 3 1 2 2

    // Test case 3
    int n3 = 0;
    vector<int> result3 = sol.countBits(n3);
    cout << "Number of bits for numbers from 0 to " << n3 << ":" << endl;
    for (int i = 0; i <= n3; i++) {
        cout << result3[i] << " ";
    }
    cout << endl; // Output: 0

    return 0;
}

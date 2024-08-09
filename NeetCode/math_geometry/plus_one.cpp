#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 0;
        for(int i = digits.size()-1; i >=0; i--) {
            if(carry > 0 || i == digits.size()-1) {
                digits[i]+=1;
                if(digits[i] > 9) {
                    carry = 1;
                    digits[i] = 0;
                } else {
                    carry = 0;
                }
            }
        }
        if(carry == 1) digits.insert(digits.begin(), 1);
        return digits;   
    }
};


void printVector(const vector<int>& vec) {
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    // Test case 1
    vector<int> digits1 = {1, 2, 3};
    cout << "Original digits: ";
    printVector(digits1);
    vector<int> result1 = sol.plusOne(digits1);
    cout << "After plusOne: ";
    printVector(result1);

    // Test case 2
    vector<int> digits2 = {9, 9, 9};
    cout << "Original digits: ";
    printVector(digits2);
    vector<int> result2 = sol.plusOne(digits2);
    cout << "After plusOne: ";
    printVector(result2);

    // Test case 3
    vector<int> digits3 = {0};
    cout << "Original digits: ";
    printVector(digits3);
    vector<int> result3 = sol.plusOne(digits3);
    cout << "After plusOne: ";
    printVector(result3);

    return 0;
}

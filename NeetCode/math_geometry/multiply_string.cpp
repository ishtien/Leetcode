#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::reverse

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        string resStr = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        vector<int> res(num1.size() + num2.size(), 0);

        for (int i = 0; i < num1.size(); i++) {
            for (int j = 0; j < num2.size(); j++) {
                int digit = (num1[i] - '0') * (num2[j] - '0');
                res[i + j] += digit;
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] = res[i + j] % 10;
            }
        }
        reverse(res.begin(), res.end());

        bool check_start = false;
        for (int i = 0; i < res.size(); i++) {
            if (res[i] != 0) check_start = true;
            if (check_start) {
                resStr += '0' + res[i];
            }
        }
        return (resStr == "") ? "0" : resStr;
    }
};

int main() {
    Solution sol;

    // Test case 1
    string num1 = "123";
    string num2 = "456";
    cout << "Multiplication of " << num1 << " and " << num2 << " is " << sol.multiply(num1, num2) << endl;

    // Test case 2
    string num1_2 = "2";
    string num2_2 = "3";
    cout << "Multiplication of " << num1_2 << " and " << num2_2 << " is " << sol.multiply(num1_2, num2_2) << endl;

    // Test case 3
    string num1_3 = "0";
    string num2_3 = "12345";
    cout << "Multiplication of " << num1_3 << " and " << num2_3 << " is " << sol.multiply(num1_3, num2_3) << endl;

    // Test case 4
    string num1_4 = "123456";
    string num2_4 = "789";
    cout << "Multiplication of " << num1_4 << " and " << num2_4 << " is " << sol.multiply(num1_4, num2_4) << endl;

    // Test case 5
    string num1_5 = "999";
    string num2_5 = "999";
    cout << "Multiplication of " << num1_5 << " and " << num2_5 << " is " << sol.multiply(num1_5, num2_5) << endl;

    return 0;
}

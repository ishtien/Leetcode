#include <iostream>
#include <vector>
#include <string>
#include <climits> // For INT_MAX

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size();
        int sz2 = word2.size();
        vector<vector<int>> cache(sz1 + 1, vector<int>(sz2 + 1, INT_MAX));
        
        // Initialize base cases
        for(int i = 0; i < sz1 + 1; i++) {
            cache[i][sz2] = sz1 - i;
        }
        for(int i = 0; i < sz2 + 1; i++) {
            cache[sz1][i] = sz2 - i;
        }

        // Fill the cache table
        for(int i = sz1 - 1; i >= 0; i--) {
            for(int j = sz2 - 1; j >= 0; j--) {
                if(word1[i] == word2[j]) {
                    cache[i][j] = cache[i + 1][j + 1];
                } else {
                    cache[i][j] = 1 + min(cache[i + 1][j + 1], min(cache[i + 1][j], cache[i][j + 1]));
                }
            }
        }
        // for(int i = 0; i < sz1 + 1; i++) {
        //     for(int j = 0; j < sz2 + 1; j ++) {
        //         cout << cache[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return cache[0][0];
    }
};

int main() {
    Solution solution;

    // Test case 1
    string word1_1 = "horse";
    string word2_1 = "ros";
    cout << "Test case 1: " << solution.minDistance(word1_1, word2_1) << endl;

    // Test case 2
    string word1_2 = "intention";
    string word2_2 = "execution";
    cout << "Test case 2: " << solution.minDistance(word1_2, word2_2) << endl;

    // Test case 3
    string word1_3 = "kitten";
    string word2_3 = "sitting";
    cout << "Test case 3: " << solution.minDistance(word1_3, word2_3) << endl;

    // Test case 4
    string word1_4 = "flaw";
    string word2_4 = "lawn";
    cout << "Test case 4: " << solution.minDistance(word1_4, word2_4) << endl;

    // Test case 5
    string word1_5 = "";
    string word2_5 = "nonempty";
    cout << "Test case 5: " << solution.minDistance(word1_5, word2_5) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definition for a Pair
class Pair {
public:
    int key;
    string value;

    Pair(int key, string value) : key(key), value(value) {}
};

class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> res;
        for(int i = 0; i < pairs.size(); i++) {
            for(int j = 0; j < i ; j++) {
                int compare_item = pairs[i].key;
                int base_item = pairs[j].key;
                if(compare_item < base_item) {
                    pairs.insert(pairs.begin() + j, pairs[i]);
                    pairs.erase(pairs.begin() + i + 1);
                    break;
                }
            }
            res.push_back(pairs);
        }
        return res;
    }
};
// Solution class containing the insertionSort method
class SolutionModify {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> res;
        for (int i = 0; i < pairs.size(); i++) {
            int j = i - 1;
            while (j >= 0 && pairs[j].key > pairs[j + 1].key) {
                swap(pairs[j], pairs[j + 1]);
                j--;
            }
            res.push_back(pairs);
        }
        return res;
    }
};

// Helper function to print the pairs
void printPairs(const vector<Pair>& pairs) {
    for (const auto& p : pairs) {
        cout << "(" << p.key << ", " << p.value << ") ";
    }
    cout << endl;
}

int main() {
    // Create a vector of Pair objects
    vector<Pair> pairs = {
        Pair(3, "three"),
        Pair(1, "one"),
        Pair(2, "two"),
        Pair(5, "five"),
        Pair(4, "four")
    };

    // Create a Solution object and call the insertionSort method
    Solution sol;
    vector<vector<Pair>> sortedSteps = sol.insertionSort(pairs);

    // Print each step of sorting
    for (const auto& step : sortedSteps) {
        printPairs(step);
    }

    return 0;
}

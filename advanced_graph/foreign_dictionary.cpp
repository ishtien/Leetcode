#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, bool> visited;
    string res = "";

    string foreignDictionary(vector<string>& words) {    
        // Initialize graph with all characters
        for (auto &word: words) {
            for (auto &alpha: word) {
                graph[alpha];
            }
        }

        // Build the graph
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i];
            string w2 = words[i + 1];
            int minLen = min(w1.size(), w2.size());

            // Invalid case: w1 is longer but a prefix of w2
            if (w1.substr(0, minLen) == w2.substr(0, minLen) && w1.size() > w2.size()) {
                return "";
            }

            // Find the first different character to determine the order
            for (int j = 0; j < minLen; j++) {
                if (w1[j] != w2[j]) {
                    graph[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        // Perform DFS to find the topological order
        for (auto &node : graph) {
            if (visited.find(node.first) == visited.end()) {
                if (dfs(node.first)) {
                    return "";
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(char ch) {
        if (visited.find(ch) != visited.end()) {
            return visited[ch];
        }
        visited[ch] = true; // Mark as visiting
        for (auto &next : graph[ch]) {
            if (dfs(next)) {
                return true; // Cycle detected
            }
        }
        visited[ch] = false; // Mark as visited
        res.push_back(ch);
        return false;
    }
};

int main() {
    Solution solution;

    // Test cases
    vector<vector<string>> testCases = {
        {"abc", "bce"},      // Valid case
        {"wrt", "wrf", "er", "ett", "rftt"}, // Valid case
        {"z", "x", "z"},     // Invalid case: cycle detected
        {"abc", "ab"}        // Invalid case: w1 is prefix of w2 but longer
    };

    for (auto& testCase : testCases) {
        cout << "Testing case: ";
        for (auto& word : testCase) {
            cout << word << " ";
        }
        cout << endl;

        string result = solution.foreignDictionary(testCase);
        if (result.empty()) {
            cout << "No valid ordering exists" << endl;
        } else {
            cout << "Valid ordering: " << result << endl;
        }
    }

    return 0;
}

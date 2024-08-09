#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if(it == wordList.end()) return 0;

        wordList.insert(wordList.begin(), beginWord);
        int sz = wordList.size();
        unordered_map<string, vector<string>> graph;
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < wordList[i].size(); j++) {
                string pattern = wordList[i].substr(0, j) + "*" + wordList[i].substr(j + 1);
                graph[pattern].push_back(wordList[i]);
            }
        }

        unordered_set<string> visited;
        queue<string> q;
        q.push(beginWord);
        visited.insert(beginWord);
        int res = 1;
        while(!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto word = q.front();
                visited.insert(word);
                q.pop();
                if(word == endWord) return res;
                for(int j = 0; j < word.size(); j++) {
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);
                    for(auto &item : graph[pattern]) {
                        if(visited.count(item)) continue;
                        q.push(item);
                    }
                }
            }
            res ++;
        }
        return 0; 
    }
};

int main() {
    Solution sol;
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    int length = sol.ladderLength(beginWord, endWord, wordList);
    cout << "Length of shortest transformation sequence: " << length << endl;

    return 0;
}

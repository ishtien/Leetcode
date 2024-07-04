#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class TrieNode {
public:
    TrieNode *child[26];
    bool endOfWord;
    TrieNode(){
        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        endOfWord = false;
    }
};
class Trie {
private:
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode *cur = root;
        int alpha;
        for(int i = 0; i < word.size(); i++) {
            alpha = word[i]-'a';
            if(cur->child[alpha] == nullptr) {
                cur-> child[alpha] = new TrieNode();
            }
            cur = cur->child[alpha];
        }
        cur -> endOfWord = true;
    }
    bool search(string word) {
        TrieNode *cur = root;
        for(int i = 0; i < word.size(); i++) {
            int alpha = word[i]-'a';
            if(cur->child[alpha] == nullptr) return false;
            cur = cur->child[alpha];
        }
        return cur->endOfWord;
    }
    TrieNode *getRoot(){return root;}
};
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie *trie = new Trie();
        unordered_set<string> res;
        for(auto word: words) {
            trie->addWord(word);
        }
        TrieNode *root = trie->getRoot();

        //search word in board;
        int ROW = board.size();
        int COL = 0;
        if(ROW > 0) COL = board[0].size();
        vector<vector<bool>> visited(ROW, vector<bool>(COL, false));

        for(int i = 0; i < ROW; i++) {
            for(int j = 0;j < COL; j++) {
                string path = "";
                dfs(i, j, board, root, res, path, visited);
            }
        }
        vector<string> final(res.begin(), res.end());
        return final;
    }
    void dfs(int i, int j, vector<vector<char>>& board, TrieNode *node, unordered_set<string>& res, string& path, vector<vector<bool>>& visited) {
        int ROW = board.size();
        int COL = 0;
        if(ROW > 0) COL = board[0].size();
        if(i < 0 || j < 0 || i >=ROW || j >=COL || visited[i][j]) return;

        int cur = board[i][j] - 'a';
        if(node->child[cur] == nullptr) return;

        TrieNode *next = node->child[cur];
        path += board[i][j];
        visited[i][j] = true;
        if(next->endOfWord) {
            res.insert(path);
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto dir: directions) {
            int x = i + dir.first;
            int y = j + dir.second;
            dfs(x, y, board, next, res, path, visited);
        }
        visited[i][j] = false;
        path.pop_back();


    }
};



int main() {
    vector<vector<char>> board = {
        {'o', 'a', 'a', 'n'},
        {'e', 't', 'a', 'e'},
        {'i', 'h', 'k', 'r'},
        {'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath", "pea", "eat", "rain"};

    Solution solution;
    vector<string> result = solution.findWords(board, words);

    cout << "Found words: ";
    for (string word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}

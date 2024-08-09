#include <iostream>
#include <string>
using namespace std;

class PrefixTreeNode {
public:
    PrefixTreeNode* child[26];
    bool endOfWord;

    PrefixTreeNode() {
        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
        endOfWord = false;
    }
    
};

class PrefixTree {
private:
    PrefixTreeNode *root;
public:
    PrefixTree() {
        root = new PrefixTreeNode();
    }
    
    void insert(string word) {
        PrefixTreeNode *cur = root;
        int alpha;
        for(int i = 0; i < word.size(); i++) {
            alpha = word[i] - 'a';
            if(cur->child[alpha] == nullptr) {
                PrefixTreeNode *newNode = new PrefixTreeNode();
                cur->child[alpha] = newNode;
            } 
            cur = cur->child[alpha];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        PrefixTreeNode *cur = root;
        for(int i = 0; i < word.size(); i++) {
            int alpha = word[i] - 'a';
            if(cur->child[alpha] == nullptr) {
                return false;
            } else {
                cur = cur->child[alpha];
            }
        }
        if(cur->endOfWord != true) return false;
        return true;
        
    }
    
    bool startsWith(string prefix) {
        PrefixTreeNode *cur = root;
        for(int i = 0; i < prefix.size(); i++) {
            int alpha = prefix[i] - 'a';
            if(cur-> child[alpha] == nullptr) {
                return false;
            } else {
                cur = cur->child[alpha];
            }
        }
        return true;
        
    }
};

int main() {
    PrefixTree prefixTree;

    // Insert some words into the prefix tree
    prefixTree.insert("apple");
    prefixTree.insert("app");
    prefixTree.insert("banana");
    prefixTree.insert("orange");

    // Test search operation
    cout << "Search 'apple': " << (prefixTree.search("apple") ? "Found" : "Not Found") << endl;
    cout << "Search 'app': " << (prefixTree.search("app") ? "Found" : "Not Found") << endl;
    cout << "Search 'banana': " << (prefixTree.search("banana") ? "Found" : "Not Found") << endl;
    cout << "Search 'grape': " << (prefixTree.search("grape") ? "Found" : "Not Found") << endl;

    // Test startsWith operation
    cout << "Starts with 'app': " << (prefixTree.startsWith("app") ? "Found" : "Not Found") << endl;
    cout << "Starts with 'ban': " << (prefixTree.startsWith("ban") ? "Found" : "Not Found") << endl;
    cout << "Starts with 'ora': " << (prefixTree.startsWith("ora") ? "Found" : "Not Found") << endl;
    cout << "Starts with 'grape': " << (prefixTree.startsWith("grape") ? "Found" : "Not Found") << endl;

    return 0;
}

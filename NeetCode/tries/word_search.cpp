#include <iostream>
#include <string>
using namespace std;

class WordNode {
public:
    WordNode * child[26];
    bool endOfWord;
    WordNode() {
        endOfWord = false;
        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};
class WordDictionary {
private:
    WordNode *root;
public:
    WordDictionary() {
        root = new WordNode();
    }
    
    void addWord(string word) {
        WordNode *cur = root;
        for(int i = 0; i < word.size(); i++) {
            int alpha = word[i] -'a';
            if(cur->child[alpha] == nullptr) {
                WordNode * newNode = new WordNode();
                cur-> child[alpha] = newNode;
            }
            cur = cur->child[alpha];
        }
        cur->endOfWord = true;
    }
    
    bool search(string word) {
        WordNode * cur = root;
        return traverse(word, 0, cur);
    }

    bool traverse(string word, int idx, WordNode *root) {
        WordNode *cur = root;
        int alpha;
        
        for(int i = idx; i < word.size(); i++) {
            alpha = word[i] - 'a';
            if(word[i] == '.') {
                bool found = false;
                for(int j = 0; j < 26; j++) {
                    if(cur->child[j] != nullptr)
                        if(traverse(word, i + 1, cur->child[j])){
                            return true;
                        }
                }
                return false;
            } else {
                if(cur->child[alpha] == nullptr) return false;                
            }
            cur = cur->child[alpha];
        }
        if(idx == word.size()-1 && word[idx]=='.') return true;
        return cur->endOfWord;
    }
};

int main() {
    WordDictionary wordDictionary;

    // Add words to the dictionary
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");

    // Test searches with regular characters
    cout << "Search 'pad': " << (wordDictionary.search("pad") ? "Found" : "Not Found") << endl;
    cout << "Search 'bad': " << (wordDictionary.search("bad") ? "Found" : "Not Found") << endl;
    cout << "Search '.ad': " << (wordDictionary.search(".ad") ? "Found" : "Not Found") << endl;
    cout << "Search 'b..': " << (wordDictionary.search("b..") ? "Found" : "Not Found") << endl;

    return 0;
}

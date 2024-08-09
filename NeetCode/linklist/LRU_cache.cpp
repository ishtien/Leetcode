#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    int key;
    Node *prev;
    Node *next;
    Node(int k, int v):key(k), val(v), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;
    void traverse_linklist() {
        Node *cur = left;
        if(cur == nullptr) return;
        cout << "Traverse : ";
        while(cur != right) {
            cout << cur->key << " ";
            cur = cur-> next;
        }
        cout << right->key << endl;
    }

    void remove() {
        Node *tmp = left ; 
        int key = left-> key;
        left = left-> next;
        left -> prev = left;
        free(tmp);
        cache.erase(key);
    }

    void insert(int key, int value) {
        Node *new_node = new Node(key, value);
        if(left == nullptr && right == nullptr) {
            left = new_node;
            right = new_node;
            new_node->next = new_node;
            new_node->prev = new_node;
        } else {
            Node *tmp = right;
            tmp-> next = new_node;
            new_node->next = new_node;
            new_node->prev = tmp;
            right = new_node;
        }       
        cache[key] = new_node;
    }

    void update(int key, int value) {
        Node *cur = cache[key];
        cur->val = value;
        if(cache[key] == left) {
            left = left -> next;
            left -> prev = left;
            right->next = cur;
            cur-> prev = right;
            cur-> next = cur;
            right = cur;
        } else if (cache[key] == right) {
            return;
        } else {
            cur-> prev-> next = cur-> next;
            cur -> next -> prev = cur -> prev;
            right -> next = cur;
            cur -> prev = right;
            cur -> next = cur;
            right = cur;
        }
    }

public:
    LRUCache(int capacity) {
        cache.clear();
        cap = capacity;
        left = nullptr;
        right = nullptr;
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end()) {
            Node *cur = cache[key];
            if (left == cache[key]){
                Node *cur = cache[key];
                left = left -> next;
                left -> prev = left;
                right->next = cur;
                cur-> prev = right;
                cur-> next = cur;
                right = cur;
            }else if(right == cache[key]) {
                return cache[key]->val;
            } else {
                cur-> prev-> next = cur-> next;
                cur -> next -> prev = cur -> prev;
                right -> next = cur;
                cur -> prev = right;
                cur -> next = cur;
                right = cur;
            }
            // traverse_linklist();
            return cache[key]->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.find(key) != cache.end()) {
            update(key, value);
        }else{ 
            if(cache.size() >= cap) remove();
            insert(key, value);
        }
        // traverse_linklist();

    }
};
int main() {
    LRUCache cache(2); // Capacity is 2
    cout << "==============================" << endl;
    cout << "Case 1 " << endl;
    cout << "cache.put(1,1)" << endl;
    cache.put(1, 1);
    cout << "cache.put(2,2)" << endl;
    cache.put(2, 2);
    cout << "cache.get(1) : " << cache.get(1) << endl; // Output: 1
    cout << "cache.put(3,3)" << endl;
    cache.put(3, 3); // evicts key 2
    cout  << "cache.get(2) : "<< cache.get(2) << endl; // Output: -1 (not found)
    cout << "cache.put(4,4)" << endl;
    cache.put(4, 4); // evicts key 1
    cout  << "cache.get(1) : "<< cache.get(1) << endl; // Output: -1 (not found)
    cout  << "cache.get(3) : "<< cache.get(3) << endl; // Output: 3
    cout  << "cache.get(4) : "<< cache.get(4) << endl; // Output: 4
    cout << "==============================" << endl;
    cout << "Case 2" << endl;
    LRUCache cache2(2);
    cout << "cache2.put(1,10)" << endl;
    cache2.put(1, 10);
    cout << "cache2.get(1) : " << cache2.get(1) << endl; // Output: 1
    cout << "cache2.put(2,20)" << endl;
    cache2.put(2, 20);
    cout << "cache2.put(3,30)" << endl;
    cache2.put(3, 30);
    cout << "cache2.get(2) : " << cache2.get(2) << endl; // Output: 1
    cout << "cache2.get(1) : " << cache2.get(1) << endl; // Output: 1
    return 0;
}




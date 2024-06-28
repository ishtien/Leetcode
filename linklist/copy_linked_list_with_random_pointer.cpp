#include <iostream>
#include <map> 
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        
        map<Node*, Node*> hmap;
        Node* cur = head;
        
        // 第一遍遍歷：複製節點並建立映射關係
        while (cur) {
            Node* copy = new Node(cur->val);
            hmap[cur] = copy;
            cur = cur->next;
        }
        
        cur = head;
        // 第二遍遍歷：設置複製節點的 next 和 random 指針
        while (cur) {
            Node* copy = hmap[cur];
            copy->next = hmap[cur->next];
            copy->random = hmap[cur->random];
            cur = cur->next;
        }
        
        // 返回新的頭節點
        return hmap[head];
    }
};

// Helper function to print the linked list with random pointers
void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << "Value: " << cur->val;
        if (cur->random)
            cout << ", Random: " << cur->random->val;
        else
            cout << ", Random: nullptr";
        cout << endl;
        cur = cur->next;
    }
}

int main() {
    // Example usage
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->random = head->next->next; // 1's random points to 3
    head->next->random = head; // 2's random points to 1
    
    // Create an instance of Solution class
    Solution solution;
    
    // Copy the linked list with random pointers
    Node* copiedList = solution.copyRandomList(head);
    
    // Print original and copied linked list
    cout << "Original list:" << endl;
    printList(head);
    
    cout << "\nCopied list:" << endl;
    printList(copiedList);
    
    // Clean up memory (assuming this is not a part of the algorithm demonstration)
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    current = copiedList;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}

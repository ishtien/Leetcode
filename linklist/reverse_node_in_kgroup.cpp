#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* getKthNode(ListNode* head, int k) {
        ListNode *cur = head;
        for(int i = 0; i < k; i++) {
            if(!cur->next) return nullptr;
            cur = cur-> next;
        }
        return cur;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* groupPrev = &dummy;
        while(true) {
            ListNode *Knode = getKthNode(groupPrev, k);
            if(!Knode) break;

            ListNode *groupEnd = groupPrev-> next;
            ListNode *groupNext = Knode-> next;

            ListNode *cur = groupPrev->next;
            ListNode *tmp = cur;
            ListNode *prev = groupNext;
            ListNode *next;

            while(cur != groupNext) {
                next = cur-> next;
                cur-> next = prev;
                prev = cur;
                cur = next;
            }
            groupPrev->next = Knode;
            groupPrev = groupEnd;
        }
        
        return dummy.next;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

// Function to create a linked list from a vector of integers
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int val : values) {
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return dummy.next;
}

// Function to delete the linked list to free memory
void deleteList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Solution sol;
    
    // Example test case
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createList(values);
    
    cout << "Original list: ";
    printList(head);
    
    int k = 3;
    ListNode* result = sol.reverseKGroup(head, k);
    
    cout << "Reversed list in groups of " << k << ": ";
    printList(result);
    
    // Clean up memory
    deleteList(result);
    
    return 0;
}

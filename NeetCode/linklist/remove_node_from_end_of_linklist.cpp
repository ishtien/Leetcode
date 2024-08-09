#include <iostream>

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *cur = head;

        // Move cur n steps ahead
        for(int i = 0; i < n; i++) {
            cur = cur->next;
        }

        // Move delete_node to the node before the one to be deleted
        ListNode *delete_node = &dummy;
        while(cur) {
            cur = cur->next;
            delete_node = delete_node->next;
        }

        // Perform deletion
        ListNode *tmp = delete_node->next;
        delete_node->next = delete_node->next->next;
        delete tmp;

        return dummy.next;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

// Main function to demonstrate the usage of ListNode struct and Solution class
int main() {
    // Example usage of ListNode
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print original list
    std::cout << "Original list: ";
    printList(head);

    // Create an instance of Solution class
    Solution solution;

    // Remove the 2nd node from the end
    int n = 2;
    ListNode* modifiedList = solution.removeNthFromEnd(head, n);

    // Print modified list
    std::cout << "List after removing " << n << "th node from the end: ";
    printList(modifiedList);

    // Clean up memory (assuming this is not a part of the algorithm demonstration)
    // In a real application, make sure to properly deallocate memory allocated with `new`.
    ListNode* current = modifiedList;
    while (current != nullptr) {
        ListNode* tmp = current;
        current = current->next;
        delete tmp;
    }

    return 0;
}

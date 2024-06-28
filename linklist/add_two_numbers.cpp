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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(l1 && l2) {
            int value = l1->val + l2->val + carry;
            ListNode *new_node = new ListNode((value) % 10);
            cur->next = new_node;
            carry = (value > 9) ? 1 : 0;
            l1 = l1->next;
            l2 = l2->next;
            cur = cur->next;
        }
        while(l1) {
            int value = l1->val + carry;
            ListNode *new_node = new ListNode((value) % 10);
            cur->next = new_node;
            carry = (value > 9) ? 1 : 0;
            l1 = l1->next;
            cur = cur->next;
        }
        while(l2) {
            int value = l2->val + carry;
            ListNode *new_node = new ListNode((value) % 10);
            cur->next = new_node;
            carry = (value > 9) ? 1 : 0;
            l2 = l2->next;
            cur = cur->next;
        }
        if(carry == 1) cur->next = new ListNode(1, nullptr);

        return dummy->next;
    }
};

// Function to print a linked list
void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur) {
        std::cout << cur->val << " ";
        cur = cur->next;
    }
    std::cout << std::endl;
}

int main() {
    // Example usage of ListNode and Solution
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // Print the original lists
    std::cout << "List l1: ";
    printList(l1);
    std::cout << "List l2: ";
    printList(l2);

    // Create an instance of Solution class
    Solution solution;

    // Add two numbers represented by l1 and l2
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the result list
    std::cout << "Result list: ";
    printList(result);

    // Clean up memory (assuming this is not a part of the algorithm demonstration)
    ListNode* current = l1;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    current = l2;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    current = result;
    while (current) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

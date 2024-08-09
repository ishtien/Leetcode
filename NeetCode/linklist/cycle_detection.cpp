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
    bool hasCycle(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next) { 
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};

int main() {
    // Example usage of ListNode and Solution
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // Create a cycle: 4 -> 2

    // Create an instance of Solution class
    Solution solution;

    // Check if the linked list has a cycle
    bool hasCycle = solution.hasCycle(head);

    if (hasCycle) {
        std::cout << "The linked list has a cycle." << std::endl;
    } else {
        std::cout << "The linked list does not have a cycle." << std::endl;
    }

    // Clean up memory (assuming this is not a part of the algorithm demonstration)
    // ListNode* current = head;
    // while (current != nullptr) {
    //     ListNode* temp = current;
    //     if(current->next) {
    //         current = current->next;
    //         temp = nullptr;
    //         delete temp;
    //     } else {
    //         break;
    //     }
    // }

    return 0;
}

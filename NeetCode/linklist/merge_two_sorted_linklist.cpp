/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode *cur = &dummy;
        while(list1 && list2) {
            if(list1->val <= list2-> val) {
                cur -> next = list1;
                list1 = list1-> next;
            } else {
                cur -> next = list2;
                list2 = list2-> next;
            }
            cur = cur-> next;
        }
        if(list1) cur-> next = list1;
        if(list2) cur-> next = list2;

        return dummy.next;
    }
};
// Main function to demonstrate the usage of ListNode struct and Solution class
int main() {
    // Example usage of ListNode
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    // Create an instance of Solution class
    Solution solution;

    // Merge two sorted linked lists
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    ListNode* current = mergedList;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Clean up memory (assuming this is not a part of the algorithm demonstration)
    // In a real application, make sure to properly deallocate memory allocated with `new`.
    delete list1;
    delete list2;

    return 0;
}

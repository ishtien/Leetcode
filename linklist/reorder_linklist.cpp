#include <iostream>
using namespace std;
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
 struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode *middle = slow;
        ListNode *cur = slow->next;
        ListNode *prev_node = nullptr;
        ListNode *next_node;

        while(cur) {
            next_node = cur-> next;
            cur-> next = prev_node;
            prev_node = cur;
            cur = next_node;
        }
        middle -> next = nullptr;

        ListNode *l1 = head;
        ListNode *l2 = prev_node;

        while(l1 && l2) {
            ListNode *l1_next = l1 -> next;
            ListNode *l2_next = l2 -> next;
            l1 -> next = l2;
            l2 -> next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }

        return;
        
    }
};

int main() {
    // create linklist: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // print linklist
    std::cout << "Original List: ";
    ListNode *current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // reorder linklist
    Solution sol;
    sol.reorderList(head);

    // 打印reordered linklist
    current = head;
    std::cout << "Reorder List: ";
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // 釋放記憶體
    current = head;
    while (current) {
        ListNode *tmp = current;
        current = current->next;
        delete tmp;
    }

    return 0;
}


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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur) {
            ListNode *tmp = cur;
            cur = cur->next;
            tmp->next = prev;
            prev = tmp;
        }
        return prev;
        
    }
};

int main() {
    // 创建一个链表: 1 -> 2 -> 3 -> 4 -> 5
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // 打印原始链表
    std::cout << "Original List: ";
    ListNode *current = head;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // 反转链表
    Solution sol;
    ListNode *reversedHead = sol.reverseList(head);

    // 打印反转后的链表
    std::cout << "Reversed List: ";
    current = reversedHead;
    while (current) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // 释放链表内存
    current = reversedHead;
    while (current) {
        ListNode *tmp = current;
        current = current->next;
        delete tmp;
    }

    return 0;
}

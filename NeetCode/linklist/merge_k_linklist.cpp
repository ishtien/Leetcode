#include <iostream>
#include <vector>
using namespace std;

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
    void printList(ListNode *merge) {
        cout << "Print List : " << endl;
        ListNode *cur = merge;
        while(cur) {
            cout << cur->val << " ";
            cur = cur-> next;
        }
        cout << endl;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0 || lists.size() == 1) return nullptr;

        while(lists.size() > 1) {
            for(int i = 0; i < lists.size()/2; i++) {
                int merge_i = ((lists.size()/2 + i ) < lists.size())?(lists.size()/2 + i ):-1;
                ListNode* merge;
                if(merge_i == -1) {
                    merge = merge2Lists(lists[i], nullptr);
                } else {
                    merge = merge2Lists(lists[i], lists[merge_i]);
                }
                lists.erase(lists.begin() + i);
                lists.erase(lists.begin() + merge_i-1);
                
                lists.push_back(merge);
            }
        }
        return lists.front();
    }
    ListNode* merge2Lists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while(l1 && l2) {
            if(l1-> val <= l2-> val) {
                cur -> next = l1;
                l1 = l1-> next;
            } else {
                cur -> next = l2;
                l2 = l2-> next;
            }
            cur = cur-> next;
        }
        if(l1) cur-> next = l1;
        if(l2) cur-> next = l2;
        return dummy-> next;
    }
};
int main() {
    // Create several linked lists for testing
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = {list1, list2, list3};

    // Create solution object
    Solution solution;

    // Merge the lists
    ListNode* mergedList = solution.mergeKLists(lists);

    // Print the merged list
    solution.printList(mergedList);

    return 0;
}
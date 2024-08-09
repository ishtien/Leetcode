#include <iostream>
#include <stack>

using namespace std;
// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        traverse(root, k, res);
        return res;
    }

    void traverse(TreeNode* root, int &k, int &res) { 
        if (root == nullptr) return;  
        traverse(root->left, k, res);
        k = k - 1;
        if (k == 0) res = root->val;
        traverse(root->right, k, res);
    }
};

class SolutionModify {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack <TreeNode*> stk;
        TreeNode* cur;
        cur = root;
        while(!stk.empty() || cur!= nullptr) {
            while(cur != nullptr) {
                stk.push(cur);
                cur = cur->left;
            }
            auto top = stk.top();
            stk.pop();
            k--;
            if(k==0) {
                return top->val;
            }
            cur = top;
            cur = cur-> right;

        }
        return -1;
    }
};


// Utility function to insert a node into BST
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }
    if (val < root->val) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

// Utility function to delete a BST
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Example usage:
    TreeNode* root = nullptr;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 6);
    insert(root, 2);
    insert(root, 4);
    insert(root, 1);

    SolutionModify solution;
    int k = 3;
    int kth_smallest = solution.kthSmallest(root, k);
    std::cout << "The " << k << "th smallest element in the BST is: " << kth_smallest << std::endl;

    // Clean up allocated memory
    deleteTree(root);

    return 0;
}

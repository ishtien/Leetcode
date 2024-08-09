#include <iostream>
#include <cmath> // For abs function
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool res = true;
        countDepth(root, res);
        return res;
    }
    
    int countDepth(TreeNode* root, bool& res) {
        if (root == nullptr) return 0;
        
        int left = countDepth(root->left, res);
        int right = countDepth(root->right, res);
        
        if (abs(left - right) > 1) res = false;
        
        return max(left, right) + 1;
    }
};

// Function to create a binary tree (for testing)
TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

int main() {
    // Create a binary tree
    TreeNode* root = createBinaryTree();
    
    // Create an instance of Solution
    Solution sol;
    
    // Check if the tree is balanced
    bool balanced = sol.isBalanced(root);
    
    // Output the result
    if (balanced) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }
    
    return 0;
}

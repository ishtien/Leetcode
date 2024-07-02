#include <iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        if (p->val != q->val) return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(!root || !subRoot) return false; 

        if(isSameTree(root, subRoot)==true) return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);

    }

    
};

// Function to create a binary tree (for testing)
TreeNode* createBinaryTree() {
    /*
     * Example binary tree:
     *     3
     *    / \
     *   4   5
     *  / \
     * 1   2
     */
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    return root;
}

// Function to create a subtree (for testing)
TreeNode* createSubtree() {
    /*
     * Example subtree:
     *   4
     *  / \
     * 1   2
     */
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);
    return subRoot;
}

int main() {
    // Create a binary tree
    TreeNode* root = createBinaryTree();
    
    // Create a subtree
    TreeNode* subRoot = createSubtree();
    
    // Create an instance of Solution
    Solution sol;
    
    // Check if the subtree is present in the binary tree
    bool isSubtree = sol.isSubtree(root, subRoot);
    
    // Output the result
    if (isSubtree) {
        cout << "The second tree is a subtree of the first tree." << endl;
    } else {
        cout << "The second tree is not a subtree of the first tree." << endl;
    }
    
    return 0;
}

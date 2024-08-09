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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val > max(p->val, q->val)) {
            return lowestCommonAncestor(root->left, p, q);
        } else if(root->val < min(p->val, q->val)) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

// Function to create a binary search tree (BST)
TreeNode* createBST() {
    /*
     * Example BST:
     *       6
     *      / \
     *     2   8
     *    / \ / \
     *   0  4 7  9
     *     / \
     *    3   5
     */
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    return root;
}

int main() {
    // Create a BST
    TreeNode* root = createBST();

    // Nodes to find LCA for
    TreeNode* p = root->left;  // Node with value 2
    TreeNode* q = root->left->right->right;  // Node with value 5

    // Create an instance of Solution
    Solution sol;

    // Find lowest common ancestor
    TreeNode* lca = sol.lowestCommonAncestor(root, p, q);

    // Output the result
    if (lca) {
        cout << "Lowest Common Ancestor of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    } else {
        cout << "One or both nodes not found in the BST." << endl;
    }

    return 0;
}

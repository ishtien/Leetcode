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
        bool res = true;

        if(!p && !q) return true;
        if((p && !q ) || (!p && q)) return false;
        if(p->val != q-> val) return false;
        
        bool left = isSameTree(p->left, q->left);
        bool right = isSameTree(p->right, q->right);
        if(!left || !right) res = false;
        return res;
    }
    bool isSameTreeModify(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;  // Both nodes are nullptr, they are the same
        if (!p || !q) return false; // One node is nullptr, the trees are different
        if (p->val != q->val) return false; // Values are different
        
        // Recursively check left and right subtrees
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

// Function to create a binary tree (for testing)
TreeNode* createBinaryTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main() {
    // Create two binary trees
    TreeNode* tree1 = createBinaryTree();
    TreeNode* tree2 = createBinaryTree();
    
    // Create an instance of Solution
    Solution sol;
    
    // Check if the two trees are the same
    bool sameTree = sol.isSameTree(tree1, tree2);
    
    // Output the result
    if (sameTree) {
        cout << "The two trees are the same." << endl;
    } else {
        cout << "The two trees are different." << endl;
    }
    
    return 0;
}

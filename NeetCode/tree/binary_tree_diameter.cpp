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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        maxlength(root, res);
        return res;
    }
    
    int maxlength(TreeNode* root, int& res) {
        if (root == nullptr) return 0;
        int left = maxlength(root->left, res);
        int right = maxlength(root->right, res);
        res = max(res, left + right);
        return 1 + max(left, right);
    }

    
};

// Example usage in main function
int main() {
    // Create a binary tree manually
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    // Create an instance of Solution
    Solution sol;
    
    // Call diameterOfBinaryTree function
    int diameter = sol.diameterOfBinaryTree(root);
    
    // Output the result
    cout << "Diameter of the binary tree: " << diameter << endl;
    
    return 0;
}

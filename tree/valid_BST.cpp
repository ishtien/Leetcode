#include <iostream>
#include <climits> // for INT_MIN and INT_MAX
#include <vector>
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
    bool isValidBST(TreeNode* root) {
        return traverse(root, INT_MIN, INT_MAX);
    }

    bool traverse(TreeNode* root, int left, int right) {
        if (root == nullptr) return true;
        if (!(root->val > left && root->val < right)) {
            return false;
        }
        return traverse(root->left, left, root->val) && traverse(root->right, root->val, right);
    }    
};

// Function to create a binary tree from a vector (level order insertion)
TreeNode* createTree(vector<int>& nodes, int idx) {
    if (idx >= nodes.size() || nodes[idx] == -1) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(nodes[idx]);
    root->left = createTree(nodes, 2 * idx + 1);
    root->right = createTree(nodes, 2 * idx + 2);
    return root;
}

// Function to delete a binary tree
void deleteTree(TreeNode* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    // Example usage:
    vector<int> nodes1 = {2, 1, 3};
    TreeNode* root1 = createTree(nodes1, 0);

    vector<int> nodes2 = {5, 1, 4, -1, -1, 3, 6};
    TreeNode* root2 = createTree(nodes2, 0);

    Solution sol;

    cout << "Checking if root1 is a valid BST: " << (sol.isValidBST(root1) ? "true" : "false") << endl;
    cout << "Checking if root2 is a valid BST: " << (sol.isValidBST(root2) ? "true" : "false") << endl;

    // Clean up allocated memory
    deleteTree(root1);
    deleteTree(root2);

    return 0;
}

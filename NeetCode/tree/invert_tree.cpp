#include <iostream>
#include <queue> // For level order traversal
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
    TreeNode* invertTree(TreeNode* root) {
        traverse(root);
        return root;
    }

    TreeNode* invertTreeModify(TreeNode* root) {
        if(root == nullptr) return nullptr;

        TreeNode* node = new TreeNode(root->val);
        node -> left = invertTree(root->right);
        node -> right = invertTree(root->left);
        
        return node;
    }

    void traverse(TreeNode* root) {
        if (!root) return;
        TreeNode* left_subtree = root->left;
        TreeNode* right_subtree = root->right;
        root->left = right_subtree;
        root->right = left_subtree;
        traverse(root->left);
        traverse(root->right);
    }

    // Function to perform level order traversal and print the tree
    void levelOrderTraversal(TreeNode* root) {
        if (!root) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                cout << node->val << " ";
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            cout << endl;
        }
    }
};

int main() {
    // Example usage
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    Solution solution;
    
    cout << "Original Tree (Level Order):" << endl;
    solution.levelOrderTraversal(root);
    
    TreeNode* invertedRoot = solution.invertTreeModify(root);

    cout << "\nInverted Tree (Level Order):" << endl;
    solution.levelOrderTraversal(invertedRoot);

    return 0;
}

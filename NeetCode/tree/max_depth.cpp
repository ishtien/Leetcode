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
    int maxDepth(TreeNode* root) {
        return countDepth(root, 0);
    }

    int countDepth(TreeNode* root, int depth) {
        if (root == nullptr) return depth;
        int left = countDepth(root->left, depth + 1);
        int right = countDepth(root->right, depth + 1);
        return max(left, right);
    }

    int maxDepthModify(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(maxDepthModify(root->left), maxDepthModify(root->right));
    }
};

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

int main() {
    // Example usage
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution solution;

    cout << "Original Tree (Level Order):" << endl;
    levelOrderTraversal(root);

    int depth = solution.maxDepthModify(root);
    cout << "\nMax Depth of the Tree: " << depth << endl;

    return 0;
}

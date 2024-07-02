#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
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
    int goodNodes(TreeNode* root) {
        int count = 0;
        if (root == nullptr) return 0;
        traverse(root, INT_MIN, count);
        return count;
    }

    void traverse(TreeNode* root, int max_value, int &count) {
        if (root == nullptr) return;
        if (max_value <= root->val) {
            count++;
        }
        max_value = max(max_value, root->val);
        traverse(root->left, max_value, count);
        traverse(root->right, max_value, count);
    }

    int goodNodesModify(TreeNode* root) {
        return helper(root, INT_MIN);
    }

    int helper(TreeNode* root, int maxVal) {
        if(root == nullptr) return 0;
       
        int cur = (root->val >= maxVal)?1:0;
        maxVal = max(maxVal, root->val);
        return cur + helper(root->left, maxVal) + helper(root->right, maxVal);    
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

int main() {
    // Example usage:
    vector<int> nodes = {3, 1, 4, 3, -1, 1, 5}; // -1 represents nullptr
    TreeNode* root = createTree(nodes, 0);

    Solution sol;
    int result = sol.goodNodes(root);

    cout << "Number of good nodes in the binary tree: " << result << endl;

    return 0;
}

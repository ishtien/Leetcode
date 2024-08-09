#include <iostream>
#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        if(root == nullptr) return res;
        q.push(root);
        while(!q.empty()) {
            vector<int> level;
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                TreeNode *node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(level);
        }
        return res;
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

// Function to print a 2D vector
void printVector(const vector<vector<int>>& vec) {
    cout << "[";
    for (const auto& level : vec) {
        cout << "[";
        for (int val : level) {
            cout << val << ",";
        }
        cout << "], ";
    }
    cout << "]" << endl;
}

int main() {
    // Example usage:
    vector<int> nodes = {3, 9, 20, -1, -1, 15, 7}; // -1 represents nullptr
    TreeNode* root = createTree(nodes, 0);

    Solution sol;
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Level order traversal:" << endl;
    printVector(result);

    return 0;
}

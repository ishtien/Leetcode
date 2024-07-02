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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightRes;
        queue<TreeNode*> q;
        if (root == nullptr) return rightRes;
        q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            TreeNode *top;
            for (int i = 0; i < sz; i++) {
                top = q.front();
                q.pop();
                if (top->left) q.push(top->left);
                if (top->right) q.push(top->right);
            }
            rightRes.push_back(top->val);
        }
        return rightRes;
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

// Function to print a vector
void printVector(const vector<int>& vec) {
    cout << "[";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << "]" << endl;
}

int main() {
    // Example usage:
    vector<int> nodes = {1, 2, 3, -1, 5, -1, 4}; // -1 represents nullptr
    TreeNode* root = createTree(nodes, 0);

    Solution sol;
    vector<int> result = sol.rightSideView(root);

    cout << "Right side view of the binary tree:" << endl;
    printVector(result);

    return 0;
}

#include <iostream>
#include <climits> // for INT_MIN
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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
    int helper(TreeNode *root){
        if(root == nullptr) return 0;
        int left = helper(root->left);
        int right = helper(root->right);
        int cur = 0;
        int return_cur = 0;
        if(left >= 0 && right >= 0) {
            cur = root->val + left + right;
            return_cur = root->val + max(left, right);
        } else {
            cur = root->val + max(0, max(left, right));
            return_cur = cur;
        }
        ans = max(ans, cur);
        return return_cur;
    }
};
class SolutionModify {
public:
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
    int helper(TreeNode *root){
        if(root == nullptr) return 0;
        int left = max(0, helper(root->left));
        int right = max(0, helper(root->right));
        int cur = root->val + left + right;
        ans = max(ans, cur);
        return root->val + max(left, right);
    }
};

// Utility function to create a binary tree from given array representation
TreeNode* createTree(vector<int>& values, int index) {
    TreeNode* root = nullptr;
    if (index < values.size()) {
        if (values[index] == -1) // -1 represents nullptr in the tree
            return nullptr;
        
        root = new TreeNode(values[index]);
        root->left = createTree(values, 2 * index + 1);
        root->right = createTree(values, 2 * index + 2);
    }
    return root;
}

// Utility function to delete a binary tree
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    // Example usage:
    // Create a binary tree: [1, 2, 3]
    vector<int> values = {1, 2, 3};
    TreeNode* root = createTree(values, 0);
    
    // Create an instance of Solution
    Solution solution;
    
    // Calculate the maximum path sum in the binary tree
    int maxPath = solution.maxPathSum(root);
    
    // Output the result
    cout << "Maximum path sum in the binary tree: " << maxPath << endl;
    
    // Clean up allocated memory (not necessary in this example since we're not deleting the tree)
    
    return 0;
}

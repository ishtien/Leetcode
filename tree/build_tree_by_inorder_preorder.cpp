#include <iostream>
#include <vector>
#include <algorithm> // for std::find and std::copy
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildHelper(preorder, inorder);
    }

    TreeNode* buildHelper(vector<int>& pre_cur, vector<int>& cur) {
        
        if(cur.size() == 0) return nullptr;
        // cout << pre_cur.size();
        int value = pre_cur[0];
        TreeNode* root = new TreeNode(value);

        auto it = find(cur.begin(), cur.end(), value);
        int copy_left = distance(cur.begin(), it);
        vector<int> left(copy_left);
        copy(cur.begin(), cur.begin() + copy_left, left.begin());

        int copy_right = distance(it + 1, cur.end());
        vector<int> right(copy_right);
        copy(it + 1, cur.end(), right.begin());

        if(left.size() > 0) {
            vector<int> pre_cur_left(pre_cur.size()-1);
            copy(pre_cur.begin()+1, pre_cur.begin()+1 + copy_left, pre_cur_left.begin());
            root->left = buildHelper(pre_cur_left, left);
        } else {
            root->left = nullptr;
        }

        if(right.size() > 0) {
            vector<int> pre_cur_right(copy_right);
            copy(pre_cur.begin()+1 + copy_left, pre_cur.end(), pre_cur_right.begin());
            root->right = buildHelper(pre_cur_right, right);
        } else {
            root->right = nullptr;
        }
        return root;       
    }
};

// class Solution {
// public:
//     TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
//         return buildHelper(preorder, inorder);
//     }

//     TreeNode* buildHelper(std::vector<int>& pre_cur, std::vector<int>& cur) {
//         if (cur.size() == 0) return nullptr;
//         int value = pre_cur[0];
//         TreeNode* root = new TreeNode(value);

//         auto it = std::find(cur.begin(), cur.end(), value);
//         int copy_left = std::distance(cur.begin(), it);
//         std::vector<int> left(cur.begin(), it);

//         int copy_right = std::distance(it, cur.end());
//         std::vector<int> right(it + 1, cur.end());

//         std::vector<int> pre_cur_left(pre_cur.begin() + 1, pre_cur.begin() + 1 + copy_left);
//         std::vector<int> pre_cur_right(pre_cur.begin() + 1 + copy_left, pre_cur.end());

//         root->left = buildHelper(pre_cur_left, left);
//         root->right = buildHelper(pre_cur_right, right);
//         return root;
//     }
// };

// Utility function to print the inorder traversal of a binary tree
void printInorder(TreeNode* root) {
    if (root) {
        printInorder(root->left);
        std::cout << root->val << " ";
        printInorder(root->right);
    }
}

int main() {
    std::vector<int> preorder = {1, 2, 3, 4};
    std::vector<int> inorder = {2, 1, 3, 4};
    // std::vector<int> preorder = {1, 2};
    // std::vector<int> inorder = {2, 1};

    Solution solution;
    TreeNode* root = solution.buildTree(preorder, inorder);

    std::cout << "Inorder traversal of the constructed tree: ";
    printInorder(root);
    std::cout << std::endl;

    // Clean up allocated memory (not necessary in this example since we're not deleting the tree)

    return 0;
}

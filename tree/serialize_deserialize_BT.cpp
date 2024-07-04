#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <iomanip> // for setw
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str;
        serializeHelper(root, str);
        return str;
    }
    void serializeHelper(TreeNode* root, string& str) {
        if(root== nullptr) {
            str += "null|";
            return;
        }
        str += to_string(root->val) + "|";
        serializeHelper(root->left, str);
        serializeHelper(root->right, str);
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tree = cutString(data);
        int i = 0;
        TreeNode *root = deserializeHelper(tree, i);
        return root;
    }
    vector<string> cutString(string data) {
        string token;
        istringstream iss(data);
        vector<string> tree;
        while(getline(iss, token, '|')) {
            if(token == "null") {
                tree.push_back("null");
            }else {
                tree.push_back(token);
            }
        }
        return tree;
    }
    TreeNode* deserializeHelper(vector<string>& tree, int& i) {
        if(tree[i] == "null") {
            i++;
            return nullptr; 
        }
        TreeNode *root = new TreeNode(stoi(tree[i]));
        i ++;
        root->left = deserializeHelper(tree, i);
        root->right = deserializeHelper(tree, i);
        return root;

    }
};


// Helper function to print the binary tree in a readable format
void printTree(TreeNode* root, int indent = 0) {
    if (root == nullptr) {
        cout << setw(indent) << "null" << endl;
        return;
    }
    cout << setw(indent) << root->val << endl;
    printTree(root->left, indent + 4);
    printTree(root->right, indent + 4);
}

int main() {
    // Create a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Initialize codec
    Codec codec;

    // Serialize the binary tree
    string serialized = codec.serialize(root);
    cout << "Serialized tree: " << serialized << endl;

    // Deserialize the serialized string back into a binary tree
    TreeNode* deserialized_root = codec.deserialize(serialized);

    // Print the deserialized binary tree
    cout << "Deserialized tree:" << endl;
    printTree(deserialized_root);

    return 0;
}

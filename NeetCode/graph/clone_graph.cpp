#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map <Node*, Node*> visited;
        Node* copy = helper(node, visited);
        return copy;
    }
    Node* helper(Node* node, unordered_map<Node*, Node*> &visited) {
        if(node == nullptr) return nullptr;
        if(visited.find(node) != visited.end()) return visited[node];

        Node *cur = new Node(node->val);
        visited[node] = cur;
        for(auto & n: node->neighbors) {
            cur->neighbors.push_back(helper(n, visited));
        }
        return cur;
    }
};


void dfs(Node* node, unordered_map<Node*, bool>& visited) {
    if(visited[node]) return;
    visited[node] = true;
    
    cout << "Node " << node->val << " neighbors: ";
    for(auto neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;
    
    for(auto neighbor : node->neighbors) {
        dfs(neighbor, visited);
    }
}

void printGraph(Node* node) {
    if(node == nullptr) return;
    
    unordered_map<Node*, bool> visited;
    dfs(node, visited);
}



// Main function for testing
int main() {
    // Example usage
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    
    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);
    
    Solution sol;
    Node* clonedNode = sol.cloneGraph(node1);
    
    // Print the cloned graph (just an example)
    cout << "Original Graph: " << endl;
    printGraph(node1);
    
    cout << "Cloned Graph: " << endl;
    printGraph(clonedNode);
    
    return 0;
}


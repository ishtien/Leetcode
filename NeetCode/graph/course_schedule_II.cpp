#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> res;
        for(auto & course: prerequisites) {
            graph[course[0]].push_back(course[1]);
        }

        unordered_set<int> visited;
        unordered_set<int> cycle;

        for(int i = 0; i < numCourses; i++) {
            if(!dfs(i, graph, res, visited, cycle)) {
                return {};
            }
        }
        return res;    
    }
    bool dfs(int node, vector<vector<int>>& graph, vector<int> &res, unordered_set<int> &visited, unordered_set<int> &cycle) {
        if(cycle.count(node)) return false;
        if(visited.count(node))return true;
        
        visited.insert(node);
        cycle.insert(node);
        for(auto &item : graph[node]) {
            if(!dfs(item, graph, res, visited, cycle)) return false;
        }
        res.push_back(node);
        cycle.erase(node);
        return true;
    }
};

int main() {
    Solution sol;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    
    vector<int> result = sol.findOrder(numCourses, prerequisites);
    
    if (result.empty()) {
        cout << "No valid course schedule exists due to cycles." << endl;
    } else {
        cout << "Valid course schedule order:" << endl;
        for (int course : result) {
            cout << course << " ";
        }
        cout << endl;
    }
    
    return 0;
}

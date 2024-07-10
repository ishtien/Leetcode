#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto graph = new vector<int>[numCourses];
        bool hascycle = false;
        for (auto &course: prerequisites) {
            int from = course[0];
            int to = course[1];
            graph[from].push_back(to);
        }
        for(int i = 0; i < numCourses; i++) {
            vector<int> visited(numCourses, false);
            traverse(i, graph, visited, hascycle); 
            if(hascycle) return false;
        }
        return true;

    }
    void traverse(int idx, vector<int>* graph, vector<int>& visited, bool &hascycle) {
        if(visited[idx] == true) {
            hascycle = true;
            return;
        }
        visited[idx] = true;
        for(auto &node : graph[idx]) {
            traverse(node, graph, visited, hascycle);   
        }
        visited[idx] = false;
        return;
    }
};


int main() {
    Solution solution;
    int numCourses = 4;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    bool canFinish = solution.canFinish(numCourses, prerequisites);

    if (canFinish) {
        cout << "Courses can be finished." << endl;
    } else {
        cout << "Courses cannot be finished due to cycle." << endl;
    }

    return 0;
}

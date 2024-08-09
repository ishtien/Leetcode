#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> graph;
        vector<string> res;
        for(auto & pos : tickets) {
            graph[pos[0]].push_back(pos[1]);
        }
        for(auto & entry : graph) {
            sort(entry.second.begin(), entry.second.end());
        }
        dfs(graph, res, "JFK", tickets);
        reverse(res.begin(), res.end());

        if(res.size() != tickets.size() + 1) return vector<string>();
        return res;
    }
    
    bool dfs(map<string, vector<string>>& graph, vector<string> &res, string cur, vector<vector<string>>& tickets) {
        if (graph.find(cur) != graph.end()) {
            vector<string> destinations = graph[cur];
            while(!destinations.empty()) {
                string dest = destinations[0];
                graph[cur].erase(graph[cur].begin());
                dfs(graph, res, dest, tickets);
                destinations = graph[cur];
            }
        }
        res.push_back(cur);
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<string>> tickets1 = {
        {"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}
    };
    vector<string> itinerary1 = sol.findItinerary(tickets1);
    
    cout << "Itinerary 1: ";
    for (const string& city : itinerary1) {
        cout << city << " ";
    }
    cout << endl;

    // Example 2
    vector<vector<string>> tickets2 = {
        {"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}
    };
    vector<string> itinerary2 = sol.findItinerary(tickets2);

    cout << "Itinerary 2: ";
    for (const string& city : itinerary2) {
        cout << city << " ";
    }
    cout << endl;

    return 0;
}

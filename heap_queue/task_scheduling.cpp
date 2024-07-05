#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxheap;
        unordered_map<char, int> count(26);
        queue<pair<int, int>> q;
        for(int i = 0; i< tasks.size() ;i++) {
            count[tasks[i]]++;
        }
        for(auto &alpha: count) {
            maxheap.push(alpha.second);
        }
        int time = 0;
        while(true) {
            if(!maxheap.empty()) {
                auto top = maxheap.top();
                maxheap.pop();
                top--;
                if(top > 0) {
                    q.push({top, time + n});
                    
                } 
            }
            if(!q.empty()) {
                auto top = q.front();
                while(time >= top.second) {
                    q.pop();
                    maxheap.push(top.first);
                    if(!q.empty()) top = q.front();
                    else break;
                } 
            }
            time ++ ;
            if(maxheap.empty() && q.empty()) break;
            
        }
        return time;
    }
};

class SolutionModify {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> maxheap;
        unordered_map<char, int> count;

        // Count frequencies of each task
        for (char task : tasks) {
            count[task]++;
        }

        // Push frequencies into max heap
        for (auto& entry : count) {
            maxheap.push(entry.second);
        }

        int time = 0;
        queue<pair<int, int>> q;

        while (true) {
            if (!maxheap.empty()) {
                int top = maxheap.top();
                maxheap.pop();
                top--;

                if (top > 0) {
                    q.push({top, time + n});
                }
            }

            if (!q.empty()) {
                auto front = q.front();
                while (!q.empty() && time >= front.second) {
                    q.pop();
                    maxheap.push(front.first);
                    if (!q.empty()) {
                        front = q.front();
                    }
                }
            }

            time++;

            if (maxheap.empty() && q.empty()) {
                break;
            }
        }

        return time;
    }
};

int main() {
    Solution sol;
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n = 2;

    int minTime = sol.leastInterval(tasks, n);
    cout << "Minimum time required: " << minTime << endl;

    SolutionModify sol_modify;

    int minTimeModify = sol_modify.leastInterval(tasks, n);
    cout << "Minimum time required: " << minTimeModify << endl;

    return 0;
}

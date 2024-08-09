#include <iostream>
#include <vector>
#include <algorithm> // for std::min and std::max
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        for(auto & interval : intervals) {
            if(newInterval[1] < interval[0]) {
                res.push_back(newInterval);
                newInterval = interval;
            } else if(newInterval[0] > interval[1]){
                res.push_back(interval);
            }else {
                newInterval[0] = min(interval[0], newInterval[0]);
                newInterval[1] = max(interval[1], newInterval[1]);
            }
        }
        res.push_back(newInterval);
        return res;
        
    }
};

void printIntervals(const std::vector<std::vector<int>>& intervals) {
    for (const auto& interval : intervals) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;
    
    // Define some intervals and a new interval to be inserted
    std::vector<std::vector<int>> intervals = {{1, 3}, {6, 9}};
    std::vector<int> newInterval = {2, 5};
    
    // Insert the new interval
    std::vector<std::vector<int>> result = solution.insert(intervals, newInterval);
    
    // Print the result
    std::cout << "Merged intervals: ";
    printIntervals(result);
    
    return 0;
}

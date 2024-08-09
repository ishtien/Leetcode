#include <iostream>
#include <vector>
#include <algorithm> // for std::sort, std::min, and std::max

using namespace std;
class SolutionModify {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        vector<int> mergeInterval = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if(mergeInterval[1]< intervals[i][0]) {
                res.push_back(mergeInterval);
                mergeInterval = intervals[i];
            } else {
                mergeInterval[0] = min(mergeInterval[0], intervals[i][0]);
                mergeInterval[1] = max(mergeInterval[1], intervals[i][1]);
            }
        }
        res.push_back(mergeInterval);
        return res;
        
    }
};

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        if(intervals.size() == 1) return intervals;
        vector<vector<int>> res;
        vector<int> mergeInterval = intervals[0];
        for(int i = 1; i < intervals.size(); i++) {
            if(mergeInterval[1]< intervals[i][0]) {
                res.push_back(mergeInterval);
                mergeInterval = intervals[i];
            } else if(mergeInterval[0] > intervals[i][1]) {
                res.push_back(intervals[i]);
            } else {
                mergeInterval[0] = min(mergeInterval[0], intervals[i][0]);
                mergeInterval[1] = max(mergeInterval[1], intervals[i][1]);
            }
        }
        res.push_back(mergeInterval);
        return res;
        
    }
};

// Function to print intervals
void printIntervals(const std::vector<std::vector<int>>& intervals) {
    for (const auto& interval : intervals) {
        std::cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;
    
    // Define some intervals
    std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
    // Call the merge function
    std::vector<std::vector<int>> mergedIntervals = solution.merge(intervals);
    
    // Print the merged intervals
    std::cout << "Merged intervals: ";
    printIntervals(mergedIntervals);
    
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm> // for std::sort and std::min

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        sort(intervals.begin(), intervals.end());
        int endpoint = intervals[0][1];
        for(int i = 1; i < intervals.size(); i++) {
            if(endpoint > intervals[i][0]) {
                res++;
                endpoint = min(endpoint, intervals[i][1]);
            } else {
                endpoint = intervals[i][1];
            }
        }
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
    std::vector<std::vector<int>> intervals1 = {{1, 3}, {2, 4}, {3, 5}, {6, 8}};
    std::vector<std::vector<int>> intervals2 = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    std::vector<std::vector<int>> intervals3 = {{1, 2}, {1, 2}, {1, 2}, {1, 2}};

    // Call the eraseOverlapIntervals function for each set of intervals
    int result1 = solution.eraseOverlapIntervals(intervals1);
    int result2 = solution.eraseOverlapIntervals(intervals2);
    int result3 = solution.eraseOverlapIntervals(intervals3);

    // Print the results
    std::cout << "Minimum number of intervals to remove for intervals1: " << result1 << std::endl;
    std::cout << "Minimum number of intervals to remove for intervals2: " << result2 << std::endl;
    std::cout << "Minimum number of intervals to remove for intervals3: " << result3 << std::endl;
    
    return 0;
}

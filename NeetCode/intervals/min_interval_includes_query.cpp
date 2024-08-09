#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

using namespace std;
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> output;
        sort(intervals.begin(), intervals.end());
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b){
            return (a[1] - a[0]) < (b[1] - b[0]);
        });

        for(auto &query : queries) {
            for(int i = 0; i < intervals.size(); i++) {
                if(query >= intervals[i][0] && query <= intervals[i][1]) {
                    output.push_back(intervals[i][1] - intervals[i][0] + 1);
                    break;
                }
                if(i == intervals.size()-1) output.push_back(-1);
            }
        }
        return output;
        
    }
};

// Function to print vectors
void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Define some intervals and queries
    std::vector<std::vector<int>> intervals = {{1, 4}, {2, 4}, {3, 6}};
    std::vector<int> queries = {2, 5, 8};

    // Call the minInterval function
    std::vector<int> result = solution.minInterval(intervals, queries);

    // Print the results
    std::cout << "Minimum intervals for each query: ";
    printVector(result);

    return 0;
}

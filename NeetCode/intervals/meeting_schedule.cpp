#include <iostream>
#include <vector>
#include <algorithm> // for std::sort

using namespace std;

// Definition of Interval class
class Interval {
public:
    int start, end;
    Interval(int start, int end) : start(start), end(end) {}
};

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size() <= 1) return true;
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        int end = intervals[0].end;
        for(int i = 1; i < intervals.size(); i++) {
            if(end <= intervals[i].start) {
                end = intervals[i].end;
            } else {
                return false;
            }
        }
        return true;
        
    }
};


// Function to print intervals
void printIntervals(const std::vector<Interval>& intervals) {
    for (const auto& interval : intervals) {
        std::cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    std::cout << std::endl;
}

int main() {
    Solution solution;

    // Define some intervals
    std::vector<Interval> intervals1 = {Interval(0, 30), Interval(5, 10), Interval(15, 20)};
    std::vector<Interval> intervals2 = {Interval(7, 10), Interval(2, 4)};
    std::vector<Interval> intervals3 = {Interval(1, 2), Interval(2, 3), Interval(3, 4)};

    // Call the canAttendMeetings function for each set of intervals
    bool result1 = solution.canAttendMeetings(intervals1);
    bool result2 = solution.canAttendMeetings(intervals2);
    bool result3 = solution.canAttendMeetings(intervals3);

    // Print the results
    std::cout << "Can attend all meetings for intervals1: " << (result1 ? "Yes" : "No") << std::endl;
    std::cout << "Can attend all meetings for intervals2: " << (result2 ? "Yes" : "No") << std::endl;
    std::cout << "Can attend all meetings for intervals3: " << (result3 ? "Yes" : "No") << std::endl;

    return 0;
}

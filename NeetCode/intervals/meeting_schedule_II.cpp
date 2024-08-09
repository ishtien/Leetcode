#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


 //Definition of Interval:
class Interval {
public:
     int start, end;
     Interval(int start, int end) {
         this->start = start;
         this->end = end;
     }
};
 

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;
        for(auto & interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        int start_ptr = 0;
        int end_ptr = 0;
        int count = 0;
        int res = 0;
        while(start_ptr < intervals.size()) {
            if(starts[start_ptr] < ends[end_ptr]) {
                count++;
                start_ptr++;
            } else {
                count--;
                end_ptr++;
            }
            res = max(count, res);
        }
        return res;
    }
};

int main() {
    // Example usage
    vector<Interval> intervals = {
        Interval(0, 30),
        Interval(5, 10),
        Interval(15, 20)
    };

    Solution sol;
    int minRooms = sol.minMeetingRooms(intervals);

    cout << "Minimum meeting rooms required: " << minRooms << endl;

    return 0;
}

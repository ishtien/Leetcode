#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class MedianFinder {
public:
    int count;
    priority_queue<int> lower;
    priority_queue<int, vector<int>, greater<int>> higher;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
        if(lower.empty()){
            lower.push(num);
            return;
        }
        if (lower.size() > higher.size()) {
            if(lower.top()>num) {
                higher.push(lower.top());
                lower.pop();
                lower.push(num);
            } else {
                higher.push(num);
            }
        } else {
            if(higher.top() < num) {
                lower.push(higher.top());
                higher.pop();
                higher.push(num);
            } else {
                lower.push(num);
            }
        }
    }
    
    double findMedian() {
        double res = 0.0;
        if(lower.size() == higher.size()) {
            res = (lower.top() + higher.top()) / 2.0;
        } else {
            if(lower.size() > higher.size()) {
                res = lower.top();
            } else {
                res = higher.top();
            }
        }
        return res;
    }
};

int main() {
    MedianFinder mf;
    
    // Adding numbers to the median finder
    mf.addNum(1);
    mf.addNum(2);
    mf.addNum(3);
    
    // Finding the median
    double median = mf.findMedian();
    cout << "Median = " << median << endl;
    
    // Adding more numbers
    mf.addNum(4);
    mf.addNum(5);
    
    // Finding the median again
    median = mf.findMedian();
    cout << "Median = " << median << endl;
    
    return 0;
}

#include <iostream>
#include <vector>
#include <climits> // For INT_MAX
#include <algorithm> // For min

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = prices;
            // two method to copy vector to other vector
            // copy(prices.begin(), prices.end(), temp.begin());
            for (auto & flight : flights) {
                int from = flight[0];
                int to = flight[1];
                int cur_price = flight[2];
                if (prices[from] != INT_MAX)
                    temp[to] = min(temp[to], prices[from] + cur_price);
            }
            prices = temp;
        }

        return (prices[dst] == INT_MAX) ? -1 : prices[dst];
    }
};

int main() {
    Solution solution;

    // Test case: 4 cities, 4 flights, starting at city 0, destination city 3, with at most 1 stop
    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100}, // flight from city 0 to city 1 with cost 100
        {1, 2, 100}, // flight from city 1 to city 2 with cost 100
        {2, 3, 100}, // flight from city 2 to city 3 with cost 100
        {0, 2, 500}  // flight from city 0 to city 2 with cost 500
    };
    int src = 0;
    int dst = 3;
    int k = 1;

    int result = solution.findCheapestPrice(n, flights, src, dst, k);
    cout << "The cheapest price from city " << src << " to city " << dst << " with at most " << k << " stops is: " << result << endl;

    return 0;
}

class Solution {
public:
    int minOperationsMaxProfit(vector<int>& cust, int boardingCost, int runningCost) {
        
        /*
        
        4gondolas
        couter clockwise
        running cost
        
        */

        int n = cust.size();
        int wait = 0;
        int profit = 0, rot = 0;
        int mx = INT_MIN;
        int idx = 0;
        while(idx < n || wait > 0) {
            wait += idx < n? cust[idx]:0;
            // cout << wait << " ";
            if(wait > 4) {
                profit += 4 * boardingCost - runningCost;
                wait -= 4;
            } else if(wait > 0) {
                profit += wait * boardingCost - runningCost;
                wait = 0;
            }

            if(mx < profit) {
                mx = profit;
                rot = idx + 1;
            }
            idx++;
        }
        return mx <= 0? -1: rot;
    }
};
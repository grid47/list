class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        if(prices.size() <= 1) return 0;
        int days = prices.size();
        vector<int> buy(days, 0), sell(days, 0);
        buy[0]= -prices[0]-fee;
        for(int i = 1; i < days; i++) {
            buy[i] = max(buy[i -1], sell[i -1]-prices[i]-fee);
            sell[i] = max(sell[i -1], buy[i - 1]+prices[i]);
        }
        return sell[days - 1];
    }
};
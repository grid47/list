
+++
authors = ["Yasir"]
title = "Leetcode 1801: Number of Orders in the Backlog"
date = "2019-11-24"
description = "Solution to Leetcode 1801"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-orders-in-the-backlog/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        
        int mod = (int) (1e9 + 7);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> sell;
        priority_queue<pair<int,int>, vector<pair<int,int>>, less<pair<int,int>>> buy;        
        
        for(auto it: orders) {
            
            if(it[2] == 0) { // For a buy order
                
                pair<int, int> top;
                while(!sell.empty() && sell.top().first <= it[0] && it[1]) {
                    top = sell.top();
                    sell.pop();
                    if(top.second > it[1]) {
                        top.second -= it[1];
                        it[1] = 0;
                        sell.push(top);
                    } else {
                        it[1] -= top.second;
                    }
                }
                if(it[1] > 0) buy.push({it[0], it[1]});
                
            } else if(it[2] == 1) {
                pair<int, int> top;
                while(!buy.empty() && buy.top().first >= it[0] && it[1]) {
                    top = buy.top();
                    buy.pop();
                    if(top.second > it[1]) {
                        top.second -= it[1];
                        it[1] = 0;
                        buy.push(top);
                    } else {
                        it[1] -= top.second;
                    }
                }
                if(it[1] > 0) sell.push({it[0], it[1]});              
            }
            
        }
        
        int cnt = 0;
        
        while(!sell.empty()) {
            auto top = sell.top();
            cnt = (cnt + top.second) % mod;
            sell.pop();
        }
        while(!buy.empty()) {
            auto top = buy.top();
            cnt = (cnt + top.second) % mod;
            buy.pop();
        }        
        return cnt;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


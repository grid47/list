
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2646: Minimize the Total Price of the Trips"
date = "2017-08-02"
description = "Solution to Leetcode 2646"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimize-the-total-price-of-the-trips/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> frq;
    int totalCost = 0;
    vector<set<int>> grid;
    vector<int> price;
    
    bool dfs(int og, int ed, int par) {
        if(og == ed) {
            return true;
        }
        for(int x: grid[og]) {
            if(x != par && dfs(x, ed, og)) {
                frq[x]++;
                totalCost += price[x];
                return true;
            }
        }
        return false;
    }
    int memo[52][52][2];
    int dp(int node, int par, bool canReduce) {

        if(memo[node][par + 1][canReduce] != -1) return memo[node][par + 1][canReduce];
        int res = 0;
        if(canReduce)
            res += (price[node]/2) * frq[node];

        for(int x: grid[node]) {
            int cur = 0;
            if(x != par) {
                if(canReduce) {
                    cur = dp(x, node, false);                    
                } else {
                    cur = max(dp(x, node, true), dp(x, node, false));                                        
                }
                res += cur;
            }
        }
        return memo[node][par + 1][canReduce] = res;
    }
    
    
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        this->price = price;
        frq.resize(n, 0);
        grid.resize(n);
        for(auto e: edges) {
            grid[e[0]].insert(e[1]);
            grid[e[1]].insert(e[0]);
        }
        for(auto t: trips) {
            frq[t[0]]++;
            totalCost += price[t[0]];
            dfs(t[0], t[1], -1);
        }
        memset(memo, -1, sizeof(memo));
        int red = 0;
        for(int i = 0; i < n; i++) {
            red = max(red, max(dp(i, -1, false), dp(i, -1, true)));
        }
        
        return totalCost - red;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

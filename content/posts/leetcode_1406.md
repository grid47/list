
+++
authors = ["Crafted by Me"]
title = "Leetcode 1406: Stone Game III"
date = "2020-12-26"
description = "Solution to Leetcode 1406"
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/stone-game-iii/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<int> pox, memo;
    
    int dp(int idx) {
        if(idx == n) return 0;
        
        if(memo[idx] != -1) return memo[idx];
        
        int ans = INT_MIN;

        for(int i = 0; i < 3 && idx + i < n; i++) {
            int sum = pox[idx] - pox[idx + i + 1];
            ans = max(ans, sum + pox[idx + i + 1] - dp(idx + i + 1));
        }

        return memo[idx] = ans;
    }
    
    string stoneGameIII(vector<int>& sv) {

        n = sv.size();
        memo.resize(n, -1);
        pox.resize(n + 1, 0);
        for(int i = n - 1; i >= 0; i--)
            pox[i] = pox[i + 1] + sv[i];
        int net = pox[0];
        int alice = dp(0);
        // cout << net << " " << net % 2 << " " << alice << " " << net / 2;
        int bob = net - alice;
        if(bob == alice) return "Tie";
        if(alice > bob) return "Alice";
        return "Bob";
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


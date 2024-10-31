
+++
authors = ["Crafted by Me"]
title = "Leetcode 2305: Fair Distribution of Cookies"
date = "2018-07-11"
description = "Solution to Leetcode 2305"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/fair-distribution-of-cookies/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int k, ans = INT_MAX;
    vector<int> cook, dist;
    
    int dp(int idx) {
        if(idx == cook.size()) {            
            int sol = dist[0];
            for(int i = 0; i < k; i++) {
                sol = max(sol, dist[i]);
            }
            ans = min(ans, sol);
            return sol;
        }

        int ans = INT_MAX;
        for(int i = 0; i < k; i++) {
            dist[i] += cook[idx];
            ans = min(ans, dp(idx + 1));
            dist[i] -= cook[idx];
        }

        return ans;
    }
    
    int distributeCookies(vector<int>& cook, int k) {
        this->k = k;
        dist.resize(k, 0);
        this->cook = cook;
        dp(0);
        return ans;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


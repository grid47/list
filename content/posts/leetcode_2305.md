
+++
authors = ["Crafted by Me"]
title = "Leetcode 2305: Fair Distribution of Cookies"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2305: Fair Distribution of Cookies in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2306: Naming a Company](https://grid47.xyz/posts/leetcode_2306) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


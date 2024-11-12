
+++
authors = ["grid47"]
title = "Leetcode 2305: Fair Distribution of Cookies"
date = "2024-03-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2305: Fair Distribution of Cookies in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Bitmask"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2305.md" >}}
---
{{< youtube 74-V6AjJ4wg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2309: Greatest English Letter in Upper and Lower Case](https://grid47.xyz/posts/leetcode-2309-greatest-english-letter-in-upper-and-lower-case-solution/) |
| --- |

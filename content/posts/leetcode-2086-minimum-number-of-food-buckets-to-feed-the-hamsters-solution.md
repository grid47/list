
+++
authors = ["grid47"]
title = "Leetcode 2086: Minimum Number of Food Buckets to Feed the Hamsters"
date = "2024-04-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2086: Minimum Number of Food Buckets to Feed the Hamsters in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> memo;
    int dp(int idx, string &ham) {
        if(idx >= ham.size()) {
            // cout << ham << "\n";
            return 0;
        }
        if(memo[idx] != -1) return memo[idx];
        
        int ans = 100001;
        if(ham[idx] == 'H') {
            if(idx + 1 < ham.size() && ham[idx + 1] == '.') {
                // ham[idx + 1] = 'C';
                ans = min(ans, 1 + dp(idx + 3, ham));
                // ham[idx + 1] = '.';
            }
            if(idx - 1 >= 0 && (ham[idx - 1] == '.')) {
                // ham[idx - 1] = 'C';
                ans = min(ans, 1 + dp(idx + 1, ham));
                // ham[idx - 1] = '.';                    
            }
        } else {
            ans = dp(idx + 1, ham);
        }
        
        return memo[idx] = ans;
    }
    
    int minimumBuckets(string ham) {
        int n = ham.size();
        memo.resize(n, -1);
        int ans = dp(0, ham);
        return ans >= 100001? -1: ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2086.md" >}}
---
{{< youtube aDb0N0ZBvZQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2087: Minimum Cost Homecoming of a Robot in a Grid](https://grid47.xyz/posts/leetcode-2087-minimum-cost-homecoming-of-a-robot-in-a-grid-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

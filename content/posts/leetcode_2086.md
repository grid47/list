
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2086: Minimum Number of Food Buckets to Feed the Hamsters"
date = "2019-02-12"
description = "Solution to Leetcode 2086"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


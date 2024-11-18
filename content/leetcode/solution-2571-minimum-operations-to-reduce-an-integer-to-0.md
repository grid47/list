
+++
authors = ["grid47"]
title = "Leetcode 2571: Minimum Operations to Reduce an Integer to 0"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2571: Minimum Operations to Reduce an Integer to 0 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Greedy","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int dp(int n) {
        if(n == 0) return 0;
        // cout << n << " " ;
        int ans = 0;
        if((n & 1) == 0) {
            ans = dp(n >> 1);
        } else {
            if(((n >> 1) & 1)== 1) {
            // if(n == 5) cout << "'" << n<< "'";                
                n += 1;
                // while((n & 1) == 0) n >>= 1;
                ans = 1 + dp(n);
            } else {
                ans = 1 + dp(n >> 1);
            }
        }
        return ans;
    }
    
    int minOperations(int n) {
        // aggregate consecutive ones
        // turn of one
        return dp(n);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2571.md" >}}
---
{{< youtube Z14XgQXPw2I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2572: Count the Number of Square-Free Subsets](https://grid47.xyz/leetcode/solution-2572-count-the-number-of-square-free-subsets/) |
| --- |

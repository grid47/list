
+++
authors = ["grid47"]
title = "Leetcode 1458: Max Dot Product of Two Subsequences"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1458: Max Dot Product of Two Subsequences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-dot-product-of-two-subsequences/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<vector<int>> dp;
    vector<int> n1, n2;
    
    int dot(int i, int j) {

        if(i == n1.size() || j == n2.size()) return INT_MIN;
        
        if(dp[i][j] != -1) return dp[i][j];

        int ans = dot(i + 1, j);
            ans = max(ans, dot(i, j + 1));
            ans = max(ans, n1[i] * n2[j]);
        
        long q = (long) n1[i] * n2[j] + dot(i + 1, j + 1);
        if(q <= INT_MAX && q >= INT_MIN)
        ans = max(ans, (int) q);

        return dp[i][j] = ans;
    }
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {

        dp.resize(nums1.size(), vector<int>(nums2.size(), -1));
        
        n1 = nums1;
        n2 = nums2;
        
        return dot(0, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1458.md" >}}
---
{{< youtube 7qT1syQcPUQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1461: Check If a String Contains All Binary Codes of Size K](https://grid47.xyz/posts/leetcode-1461-check-if-a-string-contains-all-binary-codes-of-size-k-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

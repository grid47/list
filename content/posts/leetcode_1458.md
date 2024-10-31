
+++
authors = ["Crafted by Me"]
title = "Leetcode 1458: Max Dot Product of Two Subsequences"
date = "2020-11-04"
description = "Solution to Leetcode 1458"
tags = [
    
]
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


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


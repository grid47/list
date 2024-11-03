
+++
authors = ["Crafted by Me"]
title = "Leetcode 1569: Number of Ways to Reorder Array to Get Same BST"
date = "2020-07-17"
description = "In-depth solution and explanation for Leetcode 1569: Number of Ways to Reorder Array to Get Same BST in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long mod = 1e9 + 7;
    
    vector<vector<long long>> table;
    
    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        table.resize(n);
        for(int i = 0; i < n; i++) {
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; j++)
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % mod;
        }
        
        long long ans = dfs(nums);

        return  ans % mod - 1;
    }
    
    long long dfs(vector<int> &nums) {
        int n = nums.size();
        if( n <= 2) return 1;
        
        vector<int> left, right;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[0])    left.push_back(nums[i]);
            else                    right.push_back(nums[i]);
        }
        
        long long lc = dfs(left) % mod;
        long long rc = dfs(right)% mod;
        
        return (((table[n - 1][left.size()] * lc) % mod) * rc) % mod;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1569.md" >}}
---
{{< youtube h9bfbNQa1YA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1570: Dot Product of Two Sparse Vectors](https://grid47.xyz/posts/leetcode_1570) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1569: Number of Ways to Reorder Array to Get Same BST"
date = "2020-07-13"
description = "Solution to Leetcode 1569"
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1508: Range Sum of Sorted Subarray Sums"
date = "2020-09-12"
description = "Solution to Leetcode 1508"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // binary search
        vector<int> ans;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum = (sum + nums[j]) % mod;                
                ans.push_back(sum);
            }
        }
        
        sort(ans.begin(), ans.end());
        
        int res = 0;
        for(int i = left - 1; i < right; i++)
            res = (res + ans[i]) % mod;
        
        return res;
        
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


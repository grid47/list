
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2640: Find the Score of All Prefixes of an Array"
date = "2017-08-09"
description = "Solution to Leetcode 2640"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int mx = nums[0];
        long long sum = 0;
        int n = nums.size();
        vector<long long> ans(n, 0);
        for(int i = 0; i < n; i++) {
            mx = max(mx, nums[i]);
            int scr = nums[i] + mx;
            ans[i] = i == 0? scr: ans[i - 1] + scr;
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


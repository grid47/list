
+++
authors = ["Yasir"]
title = "Leetcode 2640: Find the Score of All Prefixes of an Array"
date = "2017-08-06"
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

**Code:**

{{< highlight html >}}
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


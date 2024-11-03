
+++
authors = ["Crafted by Me"]
title = "Leetcode 1589: Maximum Sum Obtained of Any Permutation"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1589: Maximum Sum Obtained of Any Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& req) {
        int n = nums.size();
        long long res = 0;
        vector<long long> cnt(n, 0);
        for(auto& r: req) {
            cnt[r[0]]++;
            if(r[1] + 1 < n)
                cnt[r[1] +1]--;
    }
        
        for(int i = 1; i < n; i++)
            cnt[i] += cnt[i -1];
        sort(nums.begin(), nums.end());
        sort(cnt.begin(), cnt.end());
        for(int i = 0; i < n; i++)
            res +=  ((long long) nums[i] * cnt[i]);
        
        return res % 1000000007;
        }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1589.md" >}}
---
{{< youtube TyZ_FFGIZgs >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1590: Make Sum Divisible by P](https://grid47.xyz/posts/leetcode_1590) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


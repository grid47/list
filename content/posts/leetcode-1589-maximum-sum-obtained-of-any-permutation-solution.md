
+++
authors = ["grid47"]
title = "Leetcode 1589: Maximum Sum Obtained of Any Permutation"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1589: Maximum Sum Obtained of Any Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Prefix Sum"]
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
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1590: Make Sum Divisible by P](https://grid47.xyz/posts/leetcode-1590-make-sum-divisible-by-p-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
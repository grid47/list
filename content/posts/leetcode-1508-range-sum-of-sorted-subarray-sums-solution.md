
+++
authors = ["grid47"]
title = "Leetcode 1508: Range Sum of Sorted Subarray Sums"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1508: Range Sum of Sorted Subarray Sums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1508.md" >}}
---
{{< youtube 7XTGlO6b16A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1509: Minimum Difference Between Largest and Smallest Value in Three Moves](https://grid47.xyz/posts/leetcode-1509-minimum-difference-between-largest-and-smallest-value-in-three-moves-solution/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1498: Number of Subsequences That Satisfy the Given Sum Condition"
date = "2024-06-10"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1498: Number of Subsequences That Satisfy the Given Sum Condition in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "WZhNEfbGYEo"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    int pow2(int idx) {
        if(idx == 0) return 1;
        long res;
        if(idx % 2) {
            res = pow2(idx / 2);
            res = (res * res * 2) % mod;
        }else {
            res = pow2(idx / 2);
            res = (res * res) % mod;            
        }
        return res;
    }
    
    int numSubseq(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        long res = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            
            if(nums[i] * 2 > target) break;
            
            int end = target - nums[i];
            auto it = upper_bound(nums.begin(), nums.end(), end);
            
            int idx = it - nums.begin();

            res = (res + pow2(idx - i - 1)) % mod;
            
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1498.md" >}}
---
{{< youtube WZhNEfbGYEo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1502: Can Make Arithmetic Progression From Sequence](https://grid47.xyz/leetcode/solution-1502-can-make-arithmetic-progression-from-sequence/) |
| --- |

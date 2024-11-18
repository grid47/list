
+++
authors = ["grid47"]
title = "Leetcode 2369: Check if There is a Valid Partition For The Array"
date = "2024-03-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2369: Check if There is a Valid Partition For The Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int n;
    vector<int> nums, memo;
    
    bool dp(int idx) {
        if(idx == n) return true;
        
        if(memo[idx] != -1) return memo[idx];
        
        if(idx + 1 < n && nums[idx] == nums[idx + 1]) {
            if(dp(idx + 2)) return memo[idx] = true;
        }
        
        if(idx + 2 < n) {
            if(nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]) {
                if(dp(idx + 3)) return memo[idx] = true;                
            }
            if((nums[idx + 1] == nums[idx] + 1) && (nums[idx + 2] == nums[idx] + 2)) {
                if(dp(idx + 3)) return memo[idx] =true;
            }
        }

        return memo[idx] = false;
        
    }
    
    bool validPartition(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        memo.resize(n, -1);
        return dp(0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2369.md" >}}
---
{{< youtube HywUcx60BRo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2370: Longest Ideal Subsequence](https://grid47.xyz/leetcode/solution-2370-longest-ideal-subsequence/) |
| --- |

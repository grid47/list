
+++
authors = ["Crafted by Me"]
title = "Leetcode 2369: Check if There is a Valid Partition For The Array"
date = "2018-05-09"
description = "In-depth solution and explanation for Leetcode 2369: Check if There is a Valid Partition For The Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---
{{< youtube HywUcx60BRo >}}
| Next : [LeetCode #2370: Longest Ideal Subsequence](https://grid47.xyz/posts/leetcode_2370) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


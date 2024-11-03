
+++
authors = ["Crafted by Me"]
title = "Leetcode 416: Partition Equal Subset Sum"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 416: Partition Equal Subset Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-equal-subset-sum/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> nums;
    int memo[201][10001];
    
    bool dp(int idx, int sum) {
        
        if(idx == nums.size()) return sum == 0;
        
        if(memo[idx][sum] != -1) return memo[idx][sum];
        
        bool res = dp(idx + 1, sum);
        
        if(sum >= nums[idx])
            res |= dp(idx + 1, sum - nums[idx]);
        
        return memo[idx][sum] = res;
        
    }
    
    bool canPartition(vector<int>& nums) {
        this->nums = nums;
        int sum = 0;
        for(int x: nums)
            sum += x;
        
        if(sum & 1) return false;
        
        sum = sum / 2;
        
        memset(memo, -1, sizeof(memo));
        
        return dp(0, sum);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/416.md" >}}
---
{{< youtube ZFuagJEpeEU >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #417: Pacific Atlantic Water Flow](https://grid47.xyz/posts/leetcode_417) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


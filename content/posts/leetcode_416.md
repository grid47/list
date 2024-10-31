
+++
authors = ["Crafted by Me"]
title = "Leetcode 416: Partition Equal Subset Sum"
date = "2023-09-12"
description = "Solution to Leetcode 416"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


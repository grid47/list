
+++
authors = ["Yasir"]
title = "Leetcode 2770: Maximum Number of Jumps to Reach the Last Index"
date = "2017-03-30"
description = "Solution to Leetcode 2770"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    
    int target, n;
    vector<int> memo, nums;
    
    int dp(int idx) {
        
        if(idx == n - 1) return 0;
        
        if(memo[idx] != INT_MIN) return memo[idx];
        
        int ans = INT_MIN;
        for(int i = idx + 1; i < n; i++) {
            if(abs(nums[i] - nums[idx]) <= target) {
                ans = max(ans, dp(i) + 1);
            }
        }
        // cout << idx << " " << ans << "\n";
        return memo[idx] = ans;
    }
    
    int maximumJumps(vector<int>& nums, int target) {

        n = nums.size();
        this->target = target;
        this->nums = nums;
        memo.resize(n, INT_MIN);
        int ans = dp(0);
        return ans <= 0? -1: ans;

    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


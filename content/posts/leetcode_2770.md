
+++
authors = ["Crafted by Me"]
title = "Leetcode 2770: Maximum Number of Jumps to Reach the Last Index"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2770: Maximum Number of Jumps to Reach the Last Index in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/description/)

---

**Code:**

{{< highlight cpp >}}
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


---
{{< youtube _al08ON26RA >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2771: Longest Non-decreasing Subarray From Two Arrays](https://grid47.xyz/posts/leetcode_2771) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


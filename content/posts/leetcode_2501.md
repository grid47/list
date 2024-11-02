
+++
authors = ["Crafted by Me"]
title = "Leetcode 2501: Longest Square Streak in an Array"
date = "2017-12-28"
description = "Solution to Leetcode 2501"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-square-streak-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        int mx = 1;
        for(int i= 0; i < n; i++) {
            long long tmp = (long long) nums[i] * nums[i];
            if(tmp > INT_MAX) break;
            auto it = lower_bound(nums.begin(), nums.end(), tmp);
            if(it == nums.end()) break;
            int pos = it - nums.begin();
            while(pos < n && nums[i] * nums[i] == nums[pos]) {
                    dp[pos] = max(dp[pos], 1 + dp[i]);                
                    mx = max(mx, dp[pos]);  
                    pos++;
            }
        }
        return mx == 1? -1: mx;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


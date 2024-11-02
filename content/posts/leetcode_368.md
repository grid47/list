
+++
authors = ["Crafted by Me"]
title = "Leetcode 368: Largest Divisible Subset"
date = "2022-10-30"
description = "Solution to Leetcode 368"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-divisible-subset/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0) return nums;

        sort(nums.begin(), nums.end()); 

        int n = nums.size();       
        vector<vector<int>> dp(n, vector<int>(2, 0));
        
        for(int i = n - 1; i >= 0; i--) {
            dp[i][0] = 0;
            dp[i][1] = i;
            for(int j = i + 1; j < n; j++) {
                if((nums[j] % nums[i]) == 0) {
                    if(dp[i][0] < dp[j][0]) {
                        dp[i][0] = dp[j][0];
                        dp[i][1] = j;
                    }
                }
            }
            dp[i][0]++;
        }

        int mx = 0, mxi = 0;
        for(int i = 0; i < n; i++) {
            if(mx <= dp[i][0]) {
                mxi = i;
                mx = dp[i][0];
            }
        }

        vector<int> ans;
        int i = mxi;
        ans.push_back(nums[i]);
        while(dp[i][1] != i) {
            i = dp[i][1];
            ans.push_back(nums[i]);
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/368.md" >}}
---
{{< youtube wB-B8tVXaGU >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


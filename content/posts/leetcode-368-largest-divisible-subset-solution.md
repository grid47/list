
+++
authors = ["grid47"]
title = "Leetcode 368: Largest Divisible Subset"
date = "2024-10-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 368: Largest Divisible Subset in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-divisible-subset/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/368.webp" 
    alt="A sequence of numbers with the largest divisible subset glowing, showing the optimal group."
    caption="Solution to LeetCode 368: Largest Divisible Subset Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #371: Sum of Two Integers](https://grid47.xyz/posts/leetcode-371-sum-of-two-integers-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

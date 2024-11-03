
+++
authors = ["Crafted by Me"]
title = "Leetcode 689: Maximum Sum of 3 Non-Overlapping Subarrays"
date = "2022-12-14"
description = "In-depth solution and explanation for Leetcode 689: Maximum Sum of 3 Non-Overlapping Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {

        vector<int> sum = {0};
        int n = nums.size();

        for(int i = 0; i < n; i++) sum.push_back(sum.back() + nums[i]);

        vector<vector<pair<int, vector<int>>>> dp(4, vector<pair<int, vector<int>>>(n));
        
        
        for(int i = 1; i < 4; i++) {
            int mx = 0;
            int groupLeft = 3 - i;
            for(int j = n - i * k; j >= groupLeft * k; j--) {
                int rest = j + k >= n? 0: dp[i - 1][j + k].first;
                int amnt = rest + sum[j + k] - sum[j];
                if(amnt >= mx) {
                    if(i > 1) dp[i][j].second = dp[i - 1][j + k].second;
                    dp[i][j].second.push_back(j);
                    dp[i][j].first = amnt;
                    mx = amnt;
                } else dp[i][j] = dp[i][j+1];
            }
        }
        reverse(dp[3][0].second.begin(), dp[3][0].second.end());
        return dp[3][0].second;
    }

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/689.md" >}}
---
{{< youtube r_uJ9Vlqaqs >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


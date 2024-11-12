
+++
authors = ["grid47"]
title = "Leetcode 1959: Minimum Total Space Wasted With K Resizing Operations"
date = "2024-04-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1959: Minimum Total Space Wasted With K Resizing Operations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int n;
    vector<int> nums;
    int memo[201][200];
    int dp(int k, int idx) {
        if(idx == n) return 0;
        if(k == 0) return INT_MAX;

        if(memo[k][idx] != -1) return memo[k][idx];
        
        int ans = INT_MAX, sum = 0, mx = nums[idx];
        for(int j = idx; j < n; j++) {
            mx = max(mx, nums[j]);
            sum += nums[j];
            int wasted = mx * (j - idx + 1) - sum;
            int res = dp(k - 1, j + 1);
            ans = min(ans, wasted + (res == INT_MAX? INT_MAX - wasted: res));
        }
        
        return memo[k][idx] = ans;
    }
    
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        n = nums.size();
        this->nums = nums;
        memset(memo, -1, sizeof(memo));
        return dp(k + 1, 0);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1959.md" >}}
---
{{< youtube tz2j-4bP3Kc >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1961: Check If String Is a Prefix of Array](https://grid47.xyz/posts/leetcode-1961-check-if-string-is-a-prefix-of-array-solution/) |
| --- |

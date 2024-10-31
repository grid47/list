
+++
authors = ["Crafted by Me"]
title = "Leetcode 1959: Minimum Total Space Wasted With K Resizing Operations"
date = "2019-06-22"
description = "Solution to Leetcode 1959"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


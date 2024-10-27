
+++
authors = ["Yasir"]
title = "Leetcode 907: Sum of Subarray Minimums"
date = "2022-05-05"
description = "Solution to Leetcode 907"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-subarray-minimums/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        stack<pair<int, int>> stk_p;

        int n = nums.size();
        vector<int> left(n), right(n);
        // prefill, algo may not catch everything
        for(int i = 0; i < n; i++)  left[i] = i + 1;
        for(int i = 0; i < n; i++) right[i] = n - i;

        for(int i = 0; i < n; i++) {
            while(!stk_p.empty() && stk_p.top().first > nums[i]) {
                auto x = stk_p.top();
                stk_p.pop();
                right[x.second] = i - x.second;
            }
            left[i] = stk_p.empty() ? i + 1 : i - stk_p.top().second;
            stk_p.push({ nums[i], i });
        }
        
        long long ans = 0;
        int mod = (int) 1e9 + 7;
        for (int i = 0; i < n; i++)
        ans = (ans + (long) nums[i] * (long) left[i] * (long) right[i]) % mod;
        return (int) ans;
    }
};
{{< /highlight >}}


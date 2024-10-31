
+++
authors = ["Crafted by Me"]
title = "Leetcode 2602: Minimum Operations to Make All Array Elements Equal"
date = "2017-09-17"
description = "Solution to Leetcode 2602"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& q) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> ans(q.size(), 0);
        vector<long long> pre(n, 0);
        pre[0] = nums[0];
        for(int i = 1; i < n; i++)
            pre[i] = pre[i - 1] + nums[i];
        
        for(int i = 0; i < q.size(); i++) {
            auto it = lower_bound(nums.begin(), nums.end(), q[i]);
            if(it == nums.end()) {
                ans[i] = (long long)q[i] * n - pre[n - 1];
            } else {
                int idx = it - nums.begin();
                long long right = pre[n - 1] - ((idx > 0)?pre[idx - 1]: 0);
                long long left  = idx > 0? pre[idx - 1] : 0;
                ans[i] = (long long)q[i] * idx - (long long)left + (long long)right - (long long)q[i] * ((long long)n - idx);
            }
        }
        return ans;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["grid47"]
title = "Leetcode 907: Sum of Subarray Minimums"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 907: Sum of Subarray Minimums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sum-of-subarray-minimums/description/)

---
**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/907.md" >}}
---
{{< youtube aX1F2-DrBkQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #909: Snakes and Ladders](https://grid47.xyz/posts/leetcode-909-snakes-and-ladders-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
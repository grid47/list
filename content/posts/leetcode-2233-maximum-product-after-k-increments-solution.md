
+++
authors = ["grid47"]
title = "Leetcode 2233: Maximum Product After K Increments"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2233: Maximum Product After K Increments in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-product-after-k-increments/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(), nums.end());
        
        while(k--) {
            int mini = pq.top();
            pq.pop();
            pq.push(mini + 1);
        }
        
        long long ans = 1, mod = (long) 1e9 + 7;
        
        while(!pq.empty()) {
            ans = ((ans % mod) * (pq.top() % mod)) % mod;
            pq.pop();
        }
        
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2233.md" >}}
---
{{< youtube lSr-tKjbiAM >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2235: Add Two Integers](https://grid47.xyz/posts/leetcode-2235-add-two-integers-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
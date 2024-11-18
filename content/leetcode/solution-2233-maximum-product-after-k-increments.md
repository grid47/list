
+++
authors = ["grid47"]
title = "Leetcode 2233: Maximum Product After K Increments"
date = "2024-03-28"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2235: Add Two Integers](https://grid47.xyz/leetcode/solution-2235-add-two-integers/) |
| --- |

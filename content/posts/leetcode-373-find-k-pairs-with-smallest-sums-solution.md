
+++
authors = ["grid47"]
title = "Leetcode 373: Find K Pairs with Smallest Sums"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 373: Find K Pairs with Smallest Sums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n1 = nums1.size(), n2 = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;        
        for(int i = 0; i < n1 && i < k; i++) {
            pq.push({nums1[i] + nums2[0], nums1[i], nums2[0], 0});
        }
        while(!pq.empty() && ans.size() < k) {
            auto it = pq.top();
            pq.pop();
            ans.push_back({it[1], it[2]});
            if(it[3] == n2 - 1) continue;            
            it[0] = it[1] + nums2[it[3] + 1];
            it[2] = nums2[it[3] + 1];
            it[3] = it[3] + 1;
            pq.push(it);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/373.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #375: Guess Number Higher or Lower II](https://grid47.xyz/posts/leetcode-375-guess-number-higher-or-lower-ii-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

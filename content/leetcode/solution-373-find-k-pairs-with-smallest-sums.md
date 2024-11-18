
+++
authors = ["grid47"]
title = "Leetcode 373: Find K Pairs with Smallest Sums"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 373: Find K Pairs with Smallest Sums in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/373.webp" 
    alt="A series of pairs of numbers, with the smallest sum softly glowing as each pair is tested."
    caption="Solution to LeetCode 373: Find K Pairs with Smallest Sums Problem"
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #375: Guess Number Higher or Lower II](https://grid47.xyz/leetcode/solution-375-guess-number-higher-or-lower-ii/) |
| --- |

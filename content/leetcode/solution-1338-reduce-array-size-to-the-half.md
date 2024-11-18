
+++
authors = ["grid47"]
title = "Leetcode 1338: Reduce Array Size to The Half"
date = "2024-06-26"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1338: Reduce Array Size to The Half in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = ""
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/reduce-array-size-to-the-half/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(int c: arr) ++mp[c];

        vector<int> frq;
        for(auto [_, fq] : mp) frq.push_back(fq);

        sort(frq.begin(), frq.end());

        int ans = 0, i = frq.size() - 1, half = arr.size()/2, rm = 0;
        while(rm < half) {
            rm += frq[i--];
            ans++;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1338.md" >}}
---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1339: Maximum Product of Splitted Binary Tree](https://grid47.xyz/leetcode/solution-1339-maximum-product-of-splitted-binary-tree/) |
| --- |

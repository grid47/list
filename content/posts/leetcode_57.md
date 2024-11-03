
+++
authors = ["Crafted by Me"]
title = "Leetcode 57: Insert Interval"
date = "2024-09-06"
description = "In-depth solution and explanation for Leetcode 57: Insert Interval in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/insert-interval/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& it, vector<int>& n) {
        vector<vector<int>> ans;
        int i = 0;
        while(i < it.size() && it[i][1] < n[0]) {
            ans.push_back(it[i]);
            i++;
        }
        
        while(i < it.size() && it[i][0] <= n[1]) {
            n = {
                min(it[i][0], n[0]),
                max(it[i][1], n[1])
            };
            i++;
        }
        ans.push_back(n);
        while(i < it.size()) {
            ans.push_back(it[i++]);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/57.md" >}}
---
{{< youtube A8NUOmlwOlM >}}

| Next : [LeetCode #58: Length of Last Word](grid47.xyz/leetcode_58) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


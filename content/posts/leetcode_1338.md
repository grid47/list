
+++
authors = ["Crafted by Me"]
title = "Leetcode 1338: Reduce Array Size to The Half"
date = "2021-03-05"
description = "In-depth solution and explanation for Leetcode 1338: Reduce Array Size to The Half in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
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


| Next : [LeetCode #1339: Maximum Product of Splitted Binary Tree](grid47.xyz/leetcode_1339) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


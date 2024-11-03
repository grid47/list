
+++
authors = ["Crafted by Me"]
title = "Leetcode 967: Numbers With Same Consecutive Differences"
date = "2022-03-11"
description = "In-depth solution and explanation for Leetcode 967: Numbers With Same Consecutive Differences in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for(int i = 2; i <= n; i++) {
            vector<int> cur2;
            for(int x: cur) {
                int y = x % 10;
                if(y + k < 10)
                    cur2.push_back(x * 10 + y + k);
                if(k>0 && y - k >= 0)
                    cur2.push_back(x * 10 + y - k);
                
            }
            cur = cur2;
        }
        return cur;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/967.md" >}}
---


| Next : [LeetCode #968: Binary Tree Cameras](grid47.xyz/leetcode_968) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Crafted by Me"]
title = "Leetcode 670: Maximum Swap"
date = "2023-01-02"
description = "In-depth solution and explanation for Leetcode 670: Maximum Swap in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-swap/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumSwap(int num) {

        vector<int> idx(10, 0);

        string nm = to_string(num);
        for(int i = 0; i < nm.size(); i++) idx[nm[i] - '0'] = i;

        for(int i = 0; i < nm.size(); i++)
        for(int j = 9; j > nm[i] - '0'; j--) {
            if(idx[j] > i) {
                swap(nm[idx[j]], nm[i]);
                return stoi(nm);
            }
        }

        return num;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/670.md" >}}
---
{{< youtube arecn8VuQL0 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #671: Second Minimum Node In a Binary Tree](https://grid47.xyz/posts/leetcode_671) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


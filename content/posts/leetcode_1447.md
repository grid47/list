
+++
authors = ["Crafted by Me"]
title = "Leetcode 1447: Simplified Fractions"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1447: Simplified Fractions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/simplified-fractions/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        if(n == 1) return {};
        vector<string> res;
        queue<tuple<int, int, int, int>> q;
        q.emplace(0, 1, 1, 1);
        while(!q.empty()) {
            auto [num1, den1, num2, den2] = q.front();
            q.pop();
            int num = num1 + num2;
            int den = den1 + den2;
            res.push_back(to_string(num) + "/" + to_string(den));
            if(den + den1 <= n) q.emplace(num1, den1, num, den);
            if(den + den2 <= n) q.emplace(num, den, num2, den2);
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1447.md" >}}
---
{{< youtube xAPYdvSkcF8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1448: Count Good Nodes in Binary Tree](https://grid47.xyz/posts/leetcode_1448) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}


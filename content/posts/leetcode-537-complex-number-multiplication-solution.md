
+++
authors = ["grid47"]
title = "Leetcode 537: Complex Number Multiplication"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 537: Complex Number Multiplication in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/complex-number-multiplication/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        string r1, img1, r2, img2;
        int i = 0;
        while(num1[i] != '+') {
            r1 += num1[i];
            i++;
        }
        img1 = num1.substr(i + 1, num1.size() -1);
        i = 0;
        while(num2[i] != '+') {
            r2 += num2[i];
            i++;
        }
        img2 = num2.substr(i + 1, num2.size() -1);
        int re1 = stoi(r1);
        int re2 = stoi(r2);
        int ig1 = stoi(img1);
        int ig2 = stoi(img2);

        i = re1 * re2 - ig1 * ig2;
        int g = re1 * ig2 + re2 * ig1;

        return to_string(i) + "+" + to_string(g) + "i";
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/537.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #538: Convert BST to Greater Tree](https://grid47.xyz/posts/leetcode-538-convert-bst-to-greater-tree-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
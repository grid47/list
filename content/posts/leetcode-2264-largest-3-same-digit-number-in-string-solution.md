
+++
authors = ["grid47"]
title = "Leetcode 2264: Largest 3-Same-Digit Number in String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2264: Largest 3-Same-Digit Number in String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-3-same-digit-number-in-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string largestGoodInteger(string num) {
        char res = 0;
    for(int i = 2; i < num.size(); ++i)
        if (num[i] == num[i - 1] && num[i] == num[i - 2])
            res = max(res, num[i]);
    return res == 0 ? "" : string(3, res);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2264.md" >}}
---
{{< youtube vcrOpJQHsSE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2265: Count Nodes Equal to Average of Subtree](https://grid47.xyz/posts/leetcode-2265-count-nodes-equal-to-average-of-subtree-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

+++
authors = ["grid47"]
title = "Leetcode 1758: Minimum Changes To Make Alternating Binary String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1758: Minimum Changes To Make Alternating Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-changes-to-make-alternating-binary-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minOperations(string s) {
        int zero = 0, one = 0, zf = false, of = false;
        for(int i = 0; i < s.size(); i++) {
            if(zf   && s[i] == '0') zero++;
            if(!zf  && s[i] == '1') zero++;
            if(!of   && s[i] == '0') one++;
            if(of  && s[i] == '1') one++;
            zf = !zf, of = !of;
        }
        return min(zero, one);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1758.md" >}}
---
{{< youtube 9vAQdmVU2ds >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1759: Count Number of Homogenous Substrings](https://grid47.xyz/posts/leetcode-1759-count-number-of-homogenous-substrings-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
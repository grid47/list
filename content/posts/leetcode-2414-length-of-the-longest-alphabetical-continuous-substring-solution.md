
+++
authors = ["grid47"]
title = "Leetcode 2414: Length of the Longest Alphabetical Continuous Substring"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2414: Length of the Longest Alphabetical Continuous Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int x = 1, ans = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i -1] +1) {
                x++;
            } else x = 1;
            ans = max(x, ans);
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2414.md" >}}
---
{{< youtube TBVr58ynqsI >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2415: Reverse Odd Levels of Binary Tree](https://grid47.xyz/posts/leetcode-2415-reverse-odd-levels-of-binary-tree-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

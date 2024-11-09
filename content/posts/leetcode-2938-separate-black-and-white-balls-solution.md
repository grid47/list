
+++
authors = ["grid47"]
title = "Leetcode 2938: Separate Black and White Balls"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2938: Separate Black and White Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/separate-black-and-white-balls/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        for (int i = 0, cnt = 0; i < s.size(); ++i) {
            if (s[i] == '1')
                ++cnt;
            else
                res += cnt;
        }
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2938.md" >}}
---
{{< youtube -VVN0FI0KFo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2942: Find Words Containing Character](https://grid47.xyz/posts/leetcode-2942-find-words-containing-character-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}


+++
authors = ["Crafted by Me"]
title = "Leetcode 926: Flip String to Monotone Increasing"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 926: Flip String to Monotone Increasing in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/flip-string-to-monotone-increasing/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int cnt_one = 0, cnt_flip = 0;
        for(char c: s) {
            if(c == '1') cnt_one++;
            else         cnt_flip++;
            cnt_flip = min(cnt_one, cnt_flip);
        }
        return cnt_flip;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/926.md" >}}
---
{{< youtube tMq9z5k3umQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #928: Minimize Malware Spread II](https://grid47.xyz/posts/leetcode_928) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

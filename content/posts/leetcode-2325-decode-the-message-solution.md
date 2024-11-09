
+++
authors = ["grid47"]
title = "Leetcode 2325: Decode the Message"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2325: Decode the Message in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-the-message/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string decodeMessage(string key, string mess) {
        char m[128] = {}, cur = 'a';
        for (char k : key)
            if (isalpha(k) && m[k] == 0)
                m[k] = cur++;
        for (int i = 0; i < mess.size(); ++i)
            mess[i] = m[mess[i]] ?: mess[i];
        return mess;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2325.md" >}}
---
{{< youtube 4XXD2in1hwk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2326: Spiral Matrix IV](https://grid47.xyz/posts/leetcode-2326-spiral-matrix-iv-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

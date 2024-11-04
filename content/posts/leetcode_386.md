
+++
authors = ["Crafted by Me"]
title = "Leetcode 386: Lexicographical Numbers"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 386: Lexicographical Numbers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Depth-First Search","Trie"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/lexicographical-numbers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int num;
    vector<int> ans;
    vector<int> lexicalOrder(int n) {
        num = n;
        d(1);
        return ans;
    }
    void d(int x) {
        if(x > num) return;
        ans.push_back(x);
        d(x * 10);
        if((x % 10) < 9) d(x + 1);
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/386.md" >}}
---
{{< youtube n4YGTbFfU-w >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #387: First Unique Character in a String](https://grid47.xyz/posts/leetcode_387) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


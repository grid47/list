
+++
authors = ["grid47"]
title = "Leetcode 1668: Maximum Repeating Substring"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1668: Maximum Repeating Substring in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Dynamic Programming","String Matching"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-repeating-substring/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int count=0;
        string temp=word;
        while(sequence.find(temp)!=string::npos)
        {
            count++;
            temp+=word;
        }
        return count;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1668.md" >}}
---
{{< youtube glQm_MZJywk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1669: Merge In Between Linked Lists](https://grid47.xyz/posts/leetcode-1669-merge-in-between-linked-lists-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
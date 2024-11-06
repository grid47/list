
+++
authors = ["Crafted by Me"]
title = "Leetcode 1813: Sentence Similarity III"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1813: Sentence Similarity III in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/sentence-similarity-iii/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        
        deque<string> a, b;
        string tmp = "";
        
        for(char c: s1) {
            if(c == ' ') a.push_back(tmp), tmp = "";
            else tmp += c;
        }
        a.push_back(tmp), tmp = "";
        for(char c: s2) {
            if(c == ' ') b.push_back(tmp), tmp = "";
            else tmp += c;
        }        
        b.push_back(tmp), tmp = "";
        
        while(a.size() != 0 && b.size() != 0 && (a.front() == b.front())) a.pop_front(), b.pop_front();
        while(a.size() != 0 && b.size() != 0 && (a.back() == b.back())) a.pop_back(), b.pop_back();
        
        if(a.size() == 0 || b.size() == 0) return true;
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1813.md" >}}
---
{{< youtube MMMd7dMv4Ak >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1814: Count Nice Pairs in an Array](https://grid47.xyz/posts/leetcode_1814) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
USE COUPEN "GRID100FREE" FOR FREE ACCESS
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

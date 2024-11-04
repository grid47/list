
+++
authors = ["Crafted by Me"]
title = "Leetcode 3042: Count Prefix and Suffix Pairs I"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 3042: Count Prefix and Suffix Pairs I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> wds;
    
    bool pre(int i, int j) {
        int p = 0, q = 0;
        if(wds[j].size() < wds[i].size()) return false;
        while(p < wds[i].size() && q < wds[j].size() && wds[i][p] == wds[j][q]) {
            p++; q++;
        }
        return p == wds[i].size();
    }
    
    bool post(int i, int j) {
        int p = wds[i].size() - 1, q = wds[j].size() - 1;
        if(p > q) return false;
        while(p >= 0  && q >= 0 && wds[i][p] == wds[j][q]) {
            p--; q--;
        }
        return p == -1;
    }    
    
    int countPrefixSuffixPairs(vector<string>& w) {
        wds = w;
        int n = w.size(), cnt = 0;
        
        for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(pre(i, j) && post(i, j)) cnt++;
        
        return cnt;
        
    }
};
{{< /highlight >}}


---
{{< youtube wDPL8oM9rO8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3043: Find the Length of the Longest Common Prefix](https://grid47.xyz/posts/leetcode_3043) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


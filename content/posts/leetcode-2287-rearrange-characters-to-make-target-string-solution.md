
+++
authors = ["grid47"]
title = "Leetcode 2287: Rearrange Characters to Make Target String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2287: Rearrange Characters to Make Target String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/rearrange-characters-to-make-target-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> targetFreq ; 
        for(auto a : target) {
             targetFreq[a] ++;
        }
        unordered_map<char , int> sentFreq ; 
        for(auto a : s) {
            sentFreq[a] ++ ; 
        }
        int mn = INT_MAX  ; 
        for(auto a : targetFreq ) {
             mn = min(mn , sentFreq[a.first]/a.second); 
        }
        return mn ; 
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2287.md" >}}
---
{{< youtube Mgtl8CIIWX4 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2288: Apply Discount to Prices](https://grid47.xyz/posts/leetcode-2287-rearrange-characters-to-make-target-string-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

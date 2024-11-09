
+++
authors = ["grid47"]
title = "Leetcode 1880: Check if Word Equals Summation of Two Words"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1880: Check if Word Equals Summation of Two Words in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-word-equals-summation-of-two-words/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int first=0,second=0,target=0;
        for(int i=0;i<firstWord.size();i++)
            first=first*10 + (firstWord[i]-'a');
        
        for(int i=0;i<secondWord.size();i++)
            second=second*10 +(secondWord[i]-'a');
        
        for(int i=0;i<targetWord.size();i++)
            target=target*10 +(targetWord[i]-'a');
        
        
        return first+second == target;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1880.md" >}}
---
{{< youtube XdgS7eqwF2M >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1882: Process Tasks Using Servers](https://grid47.xyz/posts/leetcode-1882-process-tasks-using-servers-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

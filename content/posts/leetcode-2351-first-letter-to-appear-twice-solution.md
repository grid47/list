
+++
authors = ["grid47"]
title = "Leetcode 2351: First Letter to Appear Twice"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2351: First Letter to Appear Twice in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String","Bit Manipulation","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/first-letter-to-appear-twice/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    char repeatedCharacter(string s) {
        vector<int> v(26);
        for(char c:s){
            v[c-'a']++;
            if(v[c-'a']>1)return c;
        }
        return 'a';
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2351.md" >}}
---
{{< youtube zIFHijNYeCE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2352: Equal Row and Column Pairs](https://grid47.xyz/posts/leetcode-2352-equal-row-and-column-pairs-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
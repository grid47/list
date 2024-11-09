
+++
authors = ["grid47"]
title = "Leetcode 1717: Maximum Score From Removing Substrings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1717: Maximum Score From Removing Substrings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-score-from-removing-substrings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumGain(string s, int x, int y, char a = 'a', char b = 'b') {
        if(y > x) {
            swap(a, b);
            swap(x, y);
        }
        
        auto s1 = greedy(s, a, b), s2 = greedy(s1,  b, a);
        
        return ((s.size() - s1.size()) / 2) * x + ((s1.size() - s2.size()) / 2) * y;
    }
    string greedy(string s, char a, char b) {
        
        string st;
        
        for(char c : s) {
            if(!st.empty() && st.back() == a && c == b)
                st.pop_back();
            else st.push_back(c);
        }
        return st;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1717.md" >}}
---
{{< youtube 9wZ-TWBreTg >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1718: Construct the Lexicographically Largest Valid Sequence](https://grid47.xyz/posts/leetcode-1718-construct-the-lexicographically-largest-valid-sequence-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

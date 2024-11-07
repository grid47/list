
+++
authors = ["Crafted by Me"]
title = "Leetcode 3136: Valid Word"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3136: Valid Word in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/valid-word/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isValid(string word) {
        set<char> st;
        bool upper = false, lower = false;
        bool vowel = false, conso = false, number = false;
        
        for(char x : word) {
            
            if(x >= 'a' && x <= 'z') lower = true;
            if(x >= 'A' && x <= 'Z') upper = true;
            st.insert(x);
            if(x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' ||
               x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                    vowel = true;
            else if((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'))
                    conso  = true;
            else if(isdigit(x)) {}
            else    return false;
            
        }
        
        return vowel && conso && st.size() >= 3;
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3136.md" >}}
---
{{< youtube -sU51QkOwLY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #3137: Minimum Number of Operations to Make Word K-Periodic](https://grid47.xyz/posts/leetcode_3137) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}


+++
authors = ["grid47"]
title = "Leetcode 6: Zigzag Conversion"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 6: Zigzag Conversion in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/zigzag-conversion/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/6.jpeg" 
    alt="A ribbon of light moving in smooth, calming zigzags across a gentle curve."
    caption="Solution to LeetCode 6: Zigzag Conversion Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
#include <string>
#include <vector>
#include <iostream>
class Solution {
public:
    string convert(string str, int n) {

        int len = str.size();
        
        if(n == 1) return str;
        
        vector<string> s(n, "");

        bool down = true; int ridx = 1;
        for (int i = 0; i < len; i++) {

            s[ridx - 1] += str[i];
            if (down) ridx++;
            else      ridx--;

            if ( (ridx == n) || 
                 (ridx == 1) ) 
                down = !down;
            
        }
        string res = "";
        for(int i = 0; i < n; i++)
            res += s[i];
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/6.md" >}}
---
{{< youtube 2NMMVnxV6lo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #7: Reverse Integer](https://grid47.xyz/posts/leetcode-7-reverse-integer-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
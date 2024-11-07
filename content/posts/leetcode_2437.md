
+++
authors = ["Crafted by Me"]
title = "Leetcode 2437: Number of Valid Clock Times"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2437: Number of Valid Clock Times in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Enumeration"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-valid-clock-times/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countTime(string time) {
        int ans = 1;
        if(time[4] == '?') ans = ans * 10;
        if(time[3] == '?') ans = ans * 6;
        
        if(time[0] == '?' && time[1] == '?') ans = ans * 24;
        else{
            if(time[1] == '?'){ 
                if(time[0] == '2' ) ans = ans * 4;
                else ans = ans * 10;
            }
            if(time[0] == '?'){
                if(time[1] < '4') ans = ans * 3;
                else ans = ans * 2;
            }
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2437.md" >}}
---
{{< youtube LDYuUXRGMzE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2438: Range Product Queries of Powers](https://grid47.xyz/posts/leetcode_2438) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

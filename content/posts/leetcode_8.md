
+++
authors = ["Crafted by Me"]
title = "Leetcode 8: String to Integer (atoi)"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 8: String to Integer (atoi) in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/string-to-integer-atoi/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int sgn = 1;
        int i = 0;
        while(i < s.size() && s[i] == ' ') i++;
        if(i < s.size() && (s[i] == '+' || s[i] == '-'))
            sgn = (s[i++] == '+')? 1: -1;
        
        while(i < s.size() && s[i] >= '0' && s[i] <= '9') {
            
        if(res > INT_MAX/10 || 
        (res == INT_MAX/10 && ((s[i]-'0')>(INT_MAX %10))))
        return (sgn > 0)? INT_MAX: INT_MIN;
            
            res = res * 10 + (s[i++] - '0');
            // cout << res << " ";
        }
        
        return sgn * res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/8.md" >}}
---
{{< youtube YA0LYrKI1CQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #9: Palindrome Number](https://grid47.xyz/posts/leetcode_9) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


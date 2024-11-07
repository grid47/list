
+++
authors = ["Crafted by Me"]
title = "Leetcode 394: Decode String"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 394: Decode String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Stack","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/decode-string/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }
    
    string decode(string &s, int &i) {
        
        
        string res = "";
        
        while(i < s.size() && s[i] != ']') {
            if(!isdigit(s[i]))
                res += s[i++];
            else {
                int n = 0;
                
                while(i < s.size() && isdigit(s[i]))
                    n = n * 10 + (s[i++] - '0');
                
                i++;
                string t = decode(s, i);
                i++;
                
                while(n--> 0) res += t;
            }
        }
        
        return res;
    }
    
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/394.md" >}}
---
{{< youtube kNW1SlfDuJY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #395: Longest Substring with At Least K Repeating Characters](https://grid47.xyz/posts/leetcode_395) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

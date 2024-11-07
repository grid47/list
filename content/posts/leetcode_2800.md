
+++
authors = ["Crafted by Me"]
title = "Leetcode 2800: Shortest String That Contains Three Strings"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2800: Shortest String That Contains Three Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/shortest-string-that-contains-three-strings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    string mn(string a, string b) {
        return (a.size() < b.size() || (a.size() == b.size() && a < b))? a: b;
    }
    
    string attach(string a, string b) {
        if(a.find(b) != string::npos) return a;
        for(int i = 0; i < a.size(); i++) {
            string t1 = a.substr(i), t2 = b.substr(0, t1.size());
            if(t1 == t2) return a + b.substr(t1.size());
        }
        return a + b;
    }
    
    string solve(string a, string b, string c) {
        string t1 = attach(a, b);
        string t2 = attach(b, a);
        
        string ret1 = attach(t1, c);
        string ret2 = attach(c, t1);
        string ret3 = attach(t2, c);
        string ret4 = attach(c, t2);        
        return mn(mn(ret1, ret2), mn(ret3, ret4));
    }
    
    string minimumString(string a, string b, string c) {
        return mn(mn(solve(a, b, c), solve(a, c, b)), solve(b, c, a));
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2800.md" >}}
---
{{< youtube 920NY6GKUEk >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2806: Account Balance After Rounded Purchase](https://grid47.xyz/posts/leetcode_2806) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

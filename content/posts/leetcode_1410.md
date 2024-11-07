
+++
authors = ["Crafted by Me"]
title = "Leetcode 1410: HTML Entity Parser"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1410: HTML Entity Parser in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Hash Table","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/html-entity-parser/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string entityParser(string text) {
        
        map<string, string> mp;
        mp["&quot;"] = "\"";
        mp["&apos;"] = "\'";
        mp["&amp;"] = "&";
        mp["&gt;"] = ">";
        mp["&lt;"] = "<";
        mp["&frasl;"] = "/";
        
        string res = "";        
        int i = 0;
        while(i < text.size()) {
            if(text[i] == '&') {
                string tmp = "";
                while(i < text.size() && text[i] != ';'){
                    tmp += text[i++];
                    if(i < text.size() && text[i] == '&') {
                        res += tmp;
                        tmp = "";
                    }
                } 
                if(text[i] == ';') {
                    i++;
                    tmp += ';';
                    if(mp.count(tmp)) {
                        res += mp[tmp];
                    } else {
                        res += tmp;
                    }
                } else {
                    res += tmp;
                }
            } else {
                res += text[i++];
            }
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1410.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1414: Find the Minimum Number of Fibonacci Numbers Whose Sum Is K](https://grid47.xyz/posts/leetcode_1414) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}


+++
authors = ["grid47"]
title = "Leetcode 1410: HTML Entity Parser"
date = "2024-06-19"
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

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1414: Find the Minimum Number of Fibonacci Numbers Whose Sum Is K](https://grid47.xyz/posts/leetcode-1414-find-the-minimum-number-of-fibonacci-numbers-whose-sum-is-k-solution/) |
| --- |

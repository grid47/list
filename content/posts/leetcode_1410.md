
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1410: HTML Entity Parser"
date = "2020-12-19"
description = "Solution to Leetcode 1410"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


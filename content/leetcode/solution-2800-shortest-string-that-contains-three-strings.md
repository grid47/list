
+++
authors = ["grid47"]
title = "Leetcode 2800: Shortest String That Contains Three Strings"
date = "2024-02-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2800: Shortest String That Contains Three Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["String","Greedy","Enumeration"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "920NY6GKUEk"
img_src = ""
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2806: Account Balance After Rounded Purchase](https://grid47.xyz/leetcode/solution-2806-account-balance-after-rounded-purchase/) |
| --- |


+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2800: Shortest String That Contains Three Strings"
date = "2017-02-28"
description = "Solution to Leetcode 2800"
tags = [
    
]
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


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


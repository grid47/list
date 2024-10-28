
+++
authors = ["Yasir"]
title = "Leetcode 67: Add Binary"
date = "2024-08-23"
description = "Solution to Leetcode 67"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-binary/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string addBinary(string a, string b) {
        
        int cr = 0;
        string res = "";
        while(!a.empty() || !b.empty() || cr) {
            if(!a.empty()) {
                cr += a.back() - '0';
                a.pop_back();
            }
            if(!b.empty()) {
                cr += b.back() - '0';
                b.pop_back();
            }
            
            res = to_string(cr % 2) + res;
            cr /= 2;
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["Yasir"]
title = "Leetcode 2810: Faulty Keyboard"
date = "2017-02-18"
description = "Solution to Leetcode 2810"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/faulty-keyboard/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string finalString(string s) {
        string res = "";
        for(auto c : s){
            if(c == 'i'){
                if(res.size()){
                    reverse(res.begin(), res.end());
                }
                
            }else
             res+=c;
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


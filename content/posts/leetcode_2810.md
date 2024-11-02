
+++
authors = ["Crafted by Me"]
title = "Leetcode 2810: Faulty Keyboard"
date = "2016-02-22"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Crafted by Me"]
title = "Leetcode 402: Remove K Digits"
date = "2022-09-26"
description = "Solution to Leetcode 402"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-k-digits/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        int n = num.size();
        if(num.size() <= k) return "0";
        
        for(char c : num) {
            
            while(!ans.empty() && (ans.back() > c) && k) {
                ans.pop_back();
                k--;
            }
            
            if(!ans.empty() || c != '0') {
                ans.push_back(c);
            }
            
        }
        while(!ans.empty() && k--)
            ans.pop_back();
        if (ans.empty()) return "0";
        while (!ans.empty()) {
            num[n - 1] = ans.back();
            ans.pop_back(), n--;
        }
        return num.substr(n);
        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/402.md" >}}
---
{{< youtube cFabMOnJaq0 >}}

{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


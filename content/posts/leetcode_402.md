
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 402: Remove K Digits"
date = "2023-09-25"
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
{{< youtube nan >}}
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


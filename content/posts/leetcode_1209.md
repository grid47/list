
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1209: Remove All Adjacent Duplicates in String II"
date = "2021-07-10"
description = "Solution to Leetcode 1209"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/)

---
{{< youtube nan >}}
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stk = {{0, '#'}};
        
        for(char c : s) {
            if(stk.back().second != c)
                stk.push_back({1, c});
            else if(++stk.back().first == k)
                stk.pop_back();
        }
        
        string res;
        for(auto x: stk)
            res.append(x.first, x.second);
        
        return res;
        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["Yasir"]
title = "Leetcode 1209: Remove All Adjacent Duplicates in String II"
date = "2021-07-07"
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

**Code:**

{{< highlight html >}}
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



+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2451: Odd String Difference"
date = "2018-02-12"
description = "Solution to Leetcode 2451"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/odd-string-difference/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
    string difference(string& s) {
        string d;
        
        for (int i = 0; i < s.size() - 1; i++) {
            d += s[i + 1] - s[i];
        }
        
        return d;
    }
public:
    string oddString(vector<string>& words) {
        int  n = words[0].size();
        unordered_map<string, vector<string>> mp;
        for (auto &it : words) {
            mp[difference(it)].push_back(it);
        }
        
        for (auto &it : mp) {
            if (it.second.size() == 1) return it.second[0];
        }
        
        return "";
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["Crafted by Me"]
title = "Leetcode 2451: Odd String Difference"
date = "2018-02-16"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


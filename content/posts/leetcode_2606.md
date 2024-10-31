
+++
authors = ["Crafted by Me"]
title = "Leetcode 2606: Find the Substring With Maximum Cost"
date = "2017-09-13"
description = "Solution to Leetcode 2606"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        map<char, int> mp;
        for(int i = 0; i < chars.size(); i++) {
            mp[chars[i]] = vals[i];
        }
        for(int i = 0; i < 26; i++) {
            char x = 'a' + i;
            if(mp.count(x)) continue;
            mp[x] = i + 1;
        }
        
        int lmax = 0, gmax = 0;
        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] < lmax + mp[s[i]]) {
                lmax = lmax + mp[s[i]];
            } else lmax = mp[s[i]];
            
            gmax = max(gmax, lmax);
        }
        return gmax;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


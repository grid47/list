
+++
authors = ["Crafted by Me"]
title = "Leetcode 2516: Take K of Each Character From Left and Right"
date = "2017-12-12"
description = "Solution to Leetcode 2516"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/)

---



**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int takeCharacters(string s, int k) {
        
        map<char, int> mp;
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        if(mp['a'] < k || mp['b'] < k || mp['c'] < k) return -1;
        
        int j = 0, mx = 0;
        for(int i = 0; i < s.size(); i++) {
            // select max window which does not decrements frq below k;
            mp[s[i]]--;
            while(j <= i && mp[s[i]] < k) {
                mp[s[j]]++;
                j++;
            }
            mx = max(mx, i - j + 1);
        }
        return s.size() - mx;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


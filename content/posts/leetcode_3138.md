
+++
authors = ["Yasir"]
title = "Leetcode 3138: Minimum Length of Anagram Concatenation"
date = "2016-03-27"
description = "Solution to Leetcode 3138"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-length-of-anagram-concatenation/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minAnagramLength(string s) {
        // 12,  4
        // aaxxbb
        // bbxxaa

        int n = s.size();
        map<char, int> mp;        
        for(char x: s)
            mp[x]++;

        int mn = mp[s[0]];
        for(auto it: mp)
        mn = __gcd(mn, it.second);

        return n / mn;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


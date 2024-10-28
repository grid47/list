
+++
authors = ["Yasir"]
title = "Leetcode 424: Longest Repeating Character Replacement"
date = "2023-09-01"
description = "Solution to Leetcode 424"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-repeating-character-replacement/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char, int> ma;
        int res = 0, j = 0, mx = 0;
        for(int i =  0; i < s.size(); i++) {
            ma[s[i]]++;
            mx = max(mx, ma[s[i]]);
            if(i - j + 1 > mx + k) {
                ma[s[j]]--;
                j++;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


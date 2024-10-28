
+++
authors = ["Yasir"]
title = "Leetcode 567: Permutation in String"
date = "2023-04-11"
description = "Solution to Leetcode 567"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/permutation-in-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> p1(26, 0), p2(26, 0);
        for(char x: s1) p1[x-'a']++;
        for(int i = 0; i < s2.size(); i++) {
            if(i >= s1.size()) p2[s2[i - s1.size()] - 'a']--;
            p2[s2[i] - 'a']++;
            if(p1 == p2) return true;
        }
        return false;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


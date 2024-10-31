
+++
authors = ["Crafted by Me"]
title = "Leetcode 2390: Removing Stars From a String"
date = "2018-04-17"
description = "Solution to Leetcode 2390"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/removing-stars-from-a-string/description/)

---

{{< youtube Qln1aXh2kvQ >}}

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeStars(string s) {
        int j = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '*') s[j++] = s[i];
            else {
                j--;
            }
        }
        return s.substr(0, j);
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


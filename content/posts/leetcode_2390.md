
+++
authors = ["Yasir"]
title = "Leetcode 2390: Removing Stars From a String"
date = "2018-04-14"
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

**Code:**

{{< highlight html >}}
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
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


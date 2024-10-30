
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2414: Length of the Longest Alphabetical Continuous Substring"
date = "2018-03-23"
description = "Solution to Leetcode 2414"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/length-of-the-longest-alphabetical-continuous-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int longestContinuousSubstring(string s) {
        int x = 1, ans = 1;
        for(int i = 1; i < s.size(); i++) {
            if(s[i] == s[i -1] +1) {
                x++;
            } else x = 1;
            ans = max(x, ans);
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


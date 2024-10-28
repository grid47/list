
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 1876: Substrings of Size Three with Distinct Characters"
date = "2019-09-10"
description = "Solution to Leetcode 1876"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countGoodSubstrings(string s) {
        
        int cnt = 0;
        for(int i = 2; i < s.size(); i++)
            if(s[i] != s[i - 1] && s[i - 1] != s[i - 2] && s[i - 2] != s[i]) cnt++;

            return cnt;

    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


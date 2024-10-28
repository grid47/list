
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 2957: Remove Adjacent Almost-Equal Characters"
date = "2016-09-24"
description = "Solution to Leetcode 2957"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-adjacent-almost-equal-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int removeAlmostEqualCharacters(string s) {
        int n = s.size();
        int i = 1, cnt = 0;
        while(i < n) {
            if(s[i] == s[i - 1] || abs(s[i] - s[i - 1]) == 1) cnt++, i += 2;
            else i++;
        }
        return cnt;        
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


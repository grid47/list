
+++
authors = ["Crafted by Me"]
title = "Leetcode 1957: Delete Characters to Make Fancy String"
date = "2019-06-24"
description = "Solution to Leetcode 1957"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string makeFancyString(string s) {
        int j = 2;
        for (int i = 2; i < s.size(); ++i)
            if (s[i] != s[j - 1] || s[i] != s[j - 2])
                s[j++] = s[i];
        s.resize(min(j, (int)s.size()));
        return s;
    }
};
{{< /highlight >}}



---



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


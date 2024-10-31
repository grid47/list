
+++
authors = ["Crafted by Me"]
title = "Leetcode 1910: Remove All Occurrences of a Substring"
date = "2019-08-10"
description = "Solution to Leetcode 1910"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string x = s;
        int m = part.size(), n = s.size(), i, j;
        for(i = 0, j = 0; i < n; i++) {
            x[j++] = s[i];
            if (j >= m && x.substr(j - m, m) == part)
                j -= m;
        }
        return x.substr(0, j);
    }
};
{{< /highlight >}}



---

{{< youtube d74CJIqw268 >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


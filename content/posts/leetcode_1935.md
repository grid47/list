
+++
authors = ["Yasir"]
title = "Leetcode 1935: Maximum Number of Words You Can Type"
date = "2019-07-13"
description = "Solution to Leetcode 1935"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-words-you-can-type/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool broken[26] = {};
        for (auto ch : brokenLetters)
            broken[ch - 'a'] = true;
        int res = 0, cnt = 0;
        for (auto ch : text)
            if (ch == ' ') {
                res += cnt == 0;
                cnt = 0;
            }
            else
                cnt += broken[ch - 'a'];
        return res + (cnt == 0);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


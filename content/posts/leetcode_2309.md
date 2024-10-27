
+++
authors = ["Yasir"]
title = "Leetcode 2309: Greatest English Letter in Upper and Lower Case"
date = "2018-07-03"
description = "Solution to Leetcode 2309"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    string greatestLetter(string s) {
        int cnt[128] = {};
        for (auto ch : s)
            ++cnt[ch];
        for (auto ch = 'Z'; ch >= 'A'; --ch)
            if (cnt[ch] && cnt[ch + 'a' - 'A'])
                return string(1, ch);
        return "";
    }
};
{{< /highlight >}}


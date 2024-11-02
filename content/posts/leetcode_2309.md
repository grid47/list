
+++
authors = ["Crafted by Me"]
title = "Leetcode 2309: Greatest English Letter in Upper and Lower Case"
date = "2017-07-07"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


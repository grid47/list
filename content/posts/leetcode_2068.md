
+++
authors = ["Yasir"]
title = "Leetcode 2068: Check Whether Two Strings are Almost Equivalent"
date = "2019-03-02"
description = "Solution to Leetcode 2068"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-whether-two-strings-are-almost-equivalent/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool checkAlmostEquivalent(string s, string t) {
        int cnt[26] = {};
        for (char c : s) cnt[c - 'a']++;
        for (char c : t) cnt[c - 'a']--;
        for (int i = 0; i < 26; ++i) {
            if (abs(cnt[i]) > 3) return false;
        }
        return true;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


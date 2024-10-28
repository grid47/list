
+++
authors = ["Yasir"]
title = "Leetcode 1160: Find Words That Can Be Formed by Characters"
date = "2021-08-26"
description = "Solution to Leetcode 1160"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int cnt[26] = {}, res = 0;
        for (auto ch : chars) 
            ++cnt[ch - 'a'];
        for (auto &w : words) {
            int cnt1[26] = {}, match = true;
            for (auto ch : w)
            if (++cnt1[ch - 'a'] > cnt[ch - 'a']) {
                match = false;
                break;
            }
            if (match) 
                res += w.size();
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1002: Find Common Characters"
date = "2022-02-01"
description = "Solution to Leetcode 1002"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-common-characters/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> frq(26, INT_MAX);
        for(string& s: words) {
            vector<int> cnt(26, 0);
            for(char x: s) cnt[x - 'a']++;

            for(int i = 0; i < 26; i++)
            frq[i] = min(frq[i], cnt[i]);
        }

        vector<string> res;
        for(int i = 0; i < 26; i++)
        for(int j = 0; j < frq[i]; j++)
            res.push_back(string(1, 'a' + i));

        return res;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


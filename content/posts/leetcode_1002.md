
+++
authors = ["Yasir"]
title = "Leetcode 1002: Find Common Characters"
date = "2022-01-30"
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

{{< highlight html >}}
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


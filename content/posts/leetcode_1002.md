
+++
authors = ["Crafted by Me"]
title = "Leetcode 1002: Find Common Characters"
date = "2021-02-03"
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


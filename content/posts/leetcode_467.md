
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 467: Unique Substrings in Wraparound String"
date = "2023-07-20"
description = "Solution to Leetcode 467"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> len(26, 0);
        int cur = 1;
        len[p[0] - 'a'] = 1;
        for(int i = 1; i < p.size(); i++) {
            if((p[i] + 26 - p[i - 1]) % 26 == 1) cur++;
            else cur = 1;
            len[p[i] - 'a'] = max(len[p[i] - 'a'], cur);
        }
        return accumulate(len.begin(), len.end(), 0);
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


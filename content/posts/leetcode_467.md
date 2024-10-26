
+++
authors = ["Yasir"]
title = "Leetcode 467: Unique Substrings in Wraparound String"
date = "2023-07-18"
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

{{< highlight html >}}
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


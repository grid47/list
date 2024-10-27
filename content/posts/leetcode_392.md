
+++
authors = ["Yasir"]
title = "Leetcode 392: Is Subsequence"
date = "2023-10-02"
description = "Solution to Leetcode 392"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/is-subsequence/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == "") return true;
        int sdx = 0, tdx = 0;
        // sdx is sub seq of tdx

        for(; tdx < t.size(); tdx++) {
            if(t[tdx] == s[sdx]) sdx++;
            if(sdx == s.size()) return true;
        }
        return false;
    }
};
{{< /highlight >}}


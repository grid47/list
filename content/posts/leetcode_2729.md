
+++
authors = ["Yasir"]
title = "Leetcode 2729: Check if The Number is Fascinating"
date = "2017-05-09"
description = "Solution to Leetcode 2729"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-the-number-is-fascinating/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool isFascinating(int n) {
        int n1 = 2 * n;
        int n2 = 3 * n;
        vector<bool> yes(10, false); 
        string s = to_string(n) + to_string(n1) + to_string(n2);
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0') return false;
            if(yes[s[i] - '0']) return false;
            yes[s[i] - '0'] = true;
        }
        return true;
    }
};
{{< /highlight >}}


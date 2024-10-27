
+++
authors = ["Yasir"]
title = "Leetcode 1016: Binary String With Substrings Representing 1 To N"
date = "2022-01-16"
description = "Solution to Leetcode 1016"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    bool queryString(string s, int n) {
        for(int i = n; i > n / 2; i--) {
            string b = bitset<32>(i).to_string();
            if(s.find(b.substr(b.find('1'))) == string::npos)
                return false;
        }
        return true;
    }
};
{{< /highlight >}}


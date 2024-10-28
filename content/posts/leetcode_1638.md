
+++
authors = ["Yasir"]
title = "Leetcode 1638: Count Substrings That Differ by One Character"
date = "2020-05-05"
description = "Solution to Leetcode 1638"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-substrings-that-differ-by-one-character/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int countSubstrings(string s, string t) {
        int res = 0;
        for(int i = 0; i < s.size(); i++)
            res += helper(s, t, i, 0);
        for(int j = 1; j < t.size(); j++)
            res += helper(s, t, 0, j);
        return res;
    }

    int helper(string s, string t, int i, int j) {
        int res = 0, pre = 0, cur = 0;
        for(int n = s.size(), m = t.size(); i < n && j < m; i++, j++) {
            cur++;
            if(s[i] != t[j]) {
                pre = cur;
                cur = 0;
            }
            res += pre;
        }
        return res;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


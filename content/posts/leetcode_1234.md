
+++
authors = ["Yasir"]
title = "Leetcode 1234: Replace the Substring for Balanced String"
date = "2021-06-12"
description = "Solution to Leetcode 1234"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/replace-the-substring-for-balanced-string/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int balancedString(string s) {
        map<char, int> ma;
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]++;
        }
        int k = s.size() / 4, j = 0, res = s.size();
        for(int i = 0; i < s.size(); i++) {
            ma[s[i]]--;
        while(j < s.size() && ma['Q'] <= k && ma['W'] <= k && ma['E'] <= k && ma['R'] <= k) {
                ma[s[j]]++;
                res = min(res, i - j + 1);
                j++;
            }
        }
        return res;
    }
};
{{< /highlight >}}


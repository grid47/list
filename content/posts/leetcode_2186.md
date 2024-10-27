
+++
authors = ["Yasir"]
title = "Leetcode 2186: Minimum Number of Steps to Make Two Strings Anagram II"
date = "2018-11-03"
description = "Solution to Leetcode 2186"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram-ii/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> tsk(26, 0);
        for(char c: s)
        tsk[c - 'a']++;
        for(char c: t)
        tsk[c - 'a']--;

        int ans = 0;
        for(int a: tsk) ans += abs(a);
        return ans;
    }
};
{{< /highlight >}}


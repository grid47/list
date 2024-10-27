
+++
authors = ["Yasir"]
title = "Leetcode 2224: Minimum Number of Operations to Convert Time"
date = "2018-09-26"
description = "Solution to Leetcode 2224"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-operations-to-convert-time/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
    int getTime(string &s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3));
    }
public:
    int convertTime(string current, string correct) {
        int diff = getTime(correct) - getTime(current), ops[4] = {60,15,5,1}, ans = 0;
        for (int op : ops) {
            ans += diff / op;
            diff %= op;
        }
        return ans;
    }
};
{{< /highlight >}}



+++
authors = ["Yasir"]
title = "Leetcode 2914: Minimum Number of Changes to Make Binary String Beautiful"
date = "2016-11-05"
description = "Solution to Leetcode 2914"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    // time/space: O(n)/O(1)
    int minChanges(string s) {
        int result = 0;
        int n = s.size();
        for (int i = 0; i < n; i += 2) {
            const char& a = s[i];
            const char& b = s[i + 1];
            if (a != b) result++;
        }        
        return result;
    }
};
{{< /highlight >}}


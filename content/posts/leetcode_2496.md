
+++
authors = ["Yasir"]
title = "Leetcode 2496: Maximum Value of a String in an Array"
date = "2017-12-28"
description = "Solution to Leetcode 2496"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/description/)

---

**Code:**

{{< highlight html >}}
class Solution 
{
public:
    int maximumValue(vector<string>& strs) 
    {
        int m = 0;
        for (string s : strs)
            if (all_of(s.begin(), s.end(), ::isdigit))
                m = max(m, stoi(s));
            else
                m = max(m, (int)s.size());
        return m;
    }
};
{{< /highlight >}}


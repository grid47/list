
+++
authors = ["Crafted by Me"]
title = "Leetcode 2496: Maximum Value of a String in an Array"
date = "2018-01-02"
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

{{< highlight cpp >}}
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


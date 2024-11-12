
+++
authors = ["grid47"]
title = "Leetcode 2496: Maximum Value of a String in an Array"
date = "2024-03-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2496: Maximum Value of a String in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2496.md" >}}
---
{{< youtube uGUaazmui2k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2497: Maximum Star Sum of a Graph](https://grid47.xyz/posts/leetcode-2497-maximum-star-sum-of-a-graph-solution/) |
| --- |

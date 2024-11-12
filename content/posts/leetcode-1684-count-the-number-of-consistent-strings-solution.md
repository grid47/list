
+++
authors = ["grid47"]
title = "Leetcode 1684: Count the Number of Consistent Strings"
date = "2024-05-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1684: Count the Number of Consistent Strings in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Bit Manipulation","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/count-the-number-of-consistent-strings/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int res = words.size();
        bool mp[26] = {};
        for (char c: allowed) mp[c - 'a'] = true;
        for (string word: words) {
            for (char c: word) if (!mp[c - 'a']) {
                res--;
                break;
            }
        }
        return res;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1684.md" >}}
---
{{< youtube CFa2TgIHMN0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #1685: Sum of Absolute Differences in a Sorted Array](https://grid47.xyz/posts/leetcode-1685-sum-of-absolute-differences-in-a-sorted-array-solution/) |
| --- |

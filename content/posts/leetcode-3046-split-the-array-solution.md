
+++
authors = ["grid47"]
title = "Leetcode 3046: Split the Array"
date = "2024-01-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3046: Split the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/split-the-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {
        map<int, int> mp;
        for(int x: nums) {
            mp[x]++;
            if(mp[x] > 2) return false;
        }
        return true;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/3046.md" >}}
---
{{< youtube ItimQQYIHEw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #3081: Replace Question Marks in String to Minimize Its Value](https://grid47.xyz/posts/leetcode-3081-replace-question-marks-in-string-to-minimize-its-value-solution/) |
| --- |

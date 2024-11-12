
+++
authors = ["grid47"]
title = "Leetcode 2446: Determine if Two Events Have Conflict"
date = "2024-03-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2446: Determine if Two Events Have Conflict in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/determine-if-two-events-have-conflict/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        if(event2[0] <= event1[1] && event2[1] >= event1[0]) return true;
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2446.md" >}}
---
{{< youtube mahSMDuJL9A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2447: Number of Subarrays With GCD Equal to K](https://grid47.xyz/posts/leetcode-2447-number-of-subarrays-with-gcd-equal-to-k-solution/) |
| --- |


+++
authors = ["Crafted by Me"]
title = "Leetcode 1893: Check if All the Integers in a Range Are Covered"
date = "2019-08-28"
description = "Solution to Leetcode 1893"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int line[52] = {};
        for (auto &r : ranges) {
            line[r[0]] += 1;
            line[r[1] + 1] -= 1;
        }
        for (int i = 1, overlaps = 0; i <= right; ++i) {
            overlaps += line[i];
            if (i >= left && overlaps == 0)
                return false;
        }
        return true;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


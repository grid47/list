
+++
authors = ["grid47"]
title = "Leetcode 2784: Check if Array is Good"
date = "2024-02-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2784: Check if Array is Good in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "le-u0OA8HMM"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/check-if-array-is-good/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int cnt[201] = {}, n = nums.size() - 1;
        for (auto num : nums)
            ++cnt[num];
        return all_of(begin(cnt) + 1, begin(cnt) + n, [](int c){ return c == 1; }) && cnt[n] == 2;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2784.md" >}}
---
{{< youtube le-u0OA8HMM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2785: Sort Vowels in a String](https://grid47.xyz/leetcode/solution-2785-sort-vowels-in-a-string/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1984: Minimum Difference Between Highest and Lowest of K Scores"
date = "2024-04-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1984: Minimum Difference Between Highest and Lowest of K Scores in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "JU5XdBZZtlk"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int minimumDifference(vector<int>& nums, int k) {
    int res = INT_MAX;
    sort(begin(nums), end(nums));
    for (int i = k - 1; i < nums.size(); ++i)
        res = min(res, nums[i] - nums[i - k + 1]);
    return res;
}
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1984.md" >}}
---
{{< youtube JU5XdBZZtlk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1985: Find the Kth Largest Integer in the Array](https://grid47.xyz/leetcode/solution-1985-find-the-kth-largest-integer-in-the-array/) |
| --- |

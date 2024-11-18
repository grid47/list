
+++
authors = ["grid47"]
title = "Leetcode 1509: Minimum Difference Between Largest and Smallest Value in Three Moves"
date = "2024-06-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1509: Minimum Difference Between Largest and Smallest Value in Three Moves in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "SG7VnKzhfjo"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        /* change one element to any other value in one move */
        /* get min diff between max and min value after performing atmost 3 moves */
        if(n < 5) return 0;
        sort(nums.begin(), nums.end());
        
        return min({nums[n - 1] - nums[3], nums[n - 2] - nums[2], nums[n - 3] - nums[1], nums[n - 4] - nums[0]});
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1509.md" >}}
---
{{< youtube SG7VnKzhfjo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1512: Number of Good Pairs](https://grid47.xyz/leetcode/solution-1512-number-of-good-pairs/) |
| --- |

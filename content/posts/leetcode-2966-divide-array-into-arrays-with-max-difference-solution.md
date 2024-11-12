
+++
authors = ["grid47"]
title = "Leetcode 2966: Divide Array Into Arrays With Max Difference"
date = "2024-01-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2966: Divide Array Into Arrays With Max Difference in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int size = nums.size();
        if (size % 3 != 0)
            return vector<vector<int>>();

        sort(nums.begin(), nums.end());

        vector<vector<int>> result(size / 3, vector<int>(3));
        int groupIndex = 0;
        for (int i = 0; i < size; i += 3) {
            if (i + 2 < size && nums[i + 2] - nums[i] <= k) {
                result[groupIndex] = { nums[i], nums[i + 1], nums[i + 2] };
                groupIndex++;
            }
            else {
                return vector<vector<int>>();
            }
        }
        return result;
    }
}; 
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2966.md" >}}
---
{{< youtube XleOio1oJeo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2971: Find Polygon With the Largest Perimeter](https://grid47.xyz/posts/leetcode-2971-find-polygon-with-the-largest-perimeter-solution/) |
| --- |

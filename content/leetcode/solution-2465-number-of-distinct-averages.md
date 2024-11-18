
+++
authors = ["grid47"]
title = "Leetcode 2465: Number of Distinct Averages"
date = "2024-03-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2465: Number of Distinct Averages in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/number-of-distinct-averages/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        map<long, int> mp;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while(i < j){
            int a = nums[j--];
            int b = nums[i++];
            long c = a + b;
            mp[c] = 1;
        }
        return mp.size();
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2465.md" >}}
---
{{< youtube 2sWoLnBzuKw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2466: Count Ways To Build Good Strings](https://grid47.xyz/leetcode/solution-2466-count-ways-to-build-good-strings/) |
| --- |

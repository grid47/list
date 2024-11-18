
+++
authors = ["grid47"]
title = "Leetcode 2592: Maximize Greatness of an Array"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2592: Maximize Greatness of an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximize-greatness-of-an-array/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        // 1 1 1 2 3 3 5
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<int, int> pos;
        pos[-1] = -1;
        for(int i = 0; i < n; i++) {
            auto it = upper_bound(nums.begin() + pos[i - 1] + 1, nums.end(), nums[i]);
            if(it == nums.end()) break;
            int idx = it - nums.begin();
            pos[i] = idx;
            if(idx == n - 1) break;
        }
        return pos.size() - 1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2592.md" >}}
---
{{< youtube p1njSkWtg2U >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2593: Find Score of an Array After Marking All Elements](https://grid47.xyz/leetcode/solution-2593-find-score-of-an-array-after-marking-all-elements/) |
| --- |

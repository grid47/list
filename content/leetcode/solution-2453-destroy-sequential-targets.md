
+++
authors = ["grid47"]
title = "Leetcode 2453: Destroy Sequential Targets"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2453: Destroy Sequential Targets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "zhvKbUSFzQ8"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/destroy-sequential-targets/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int ans = INT_MAX;
        unordered_map<int, int> mp;
        int mx = INT_MIN;
        for(int n: nums) {
            int r = n % space;
            mp[r]++;
            if(mx < mp[r]) mx = mp[r];
        }
        for(int n : nums)
        if(mx == mp[n %space]) ans = min(ans, n);
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2453.md" >}}
---
{{< youtube zhvKbUSFzQ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2455: Average Value of Even Numbers That Are Divisible by Three](https://grid47.xyz/leetcode/solution-2455-average-value-of-even-numbers-that-are-divisible-by-three/) |
| --- |

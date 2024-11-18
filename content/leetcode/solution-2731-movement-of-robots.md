
+++
authors = ["grid47"]
title = "Leetcode 2731: Movement of Robots"
date = "2024-02-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2731: Movement of Robots in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Brainteaser","Sorting","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "L86PHNze5RM"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/movement-of-robots/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        for(int i = 0; i < nums.size(); i++) {
            if(s[i] == 'L') nums[i] -= d;
            else nums[i] += d;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0, dist = 0, mod = (int) 1e9 + 7;
        for(int i = 1; i < n; i++) {
            dist += ((long)nums[i] - nums[i - 1]) * (i);
            ans = (ans + dist) % mod;
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2731.md" >}}
---
{{< youtube L86PHNze5RM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2733: Neither Minimum nor Maximum](https://grid47.xyz/leetcode/solution-2733-neither-minimum-nor-maximum/) |
| --- |

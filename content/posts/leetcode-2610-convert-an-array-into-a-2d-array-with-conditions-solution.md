
+++
authors = ["grid47"]
title = "Leetcode 2610: Convert an Array Into a 2D Array With Conditions"
date = "2024-02-20"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2610: Convert an Array Into a 2D Array With Conditions in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        map<int, int> mp;
        int mx = 0;
        for(int x: nums) {
            mp[x]++;
            mx = max(mp[x], mx);
        }
        vector<vector<int>> grid(mx);
        for(auto it: mp) {
            for(int i = 0; i < it.second; i++) {
                grid[i].push_back(it.first);
            }
        }
        return grid;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2610.md" >}}
---
{{< youtube 9pl1QiaGgmI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Udemy Course](https://grid47.xyz/courses/) / Next : [LeetCode #2611: Mice and Cheese](https://grid47.xyz/posts/leetcode-2611-mice-and-cheese-solution/) |
| --- |

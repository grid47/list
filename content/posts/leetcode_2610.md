
+++
authors = ["Crafted by Me"]
title = "Leetcode 2610: Convert an Array Into a 2D Array With Conditions"
date = "2016-09-09"
description = "Solution to Leetcode 2610"
tags = [
    
]
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


---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


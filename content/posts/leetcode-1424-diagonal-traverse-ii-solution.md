
+++
authors = ["grid47"]
title = "Leetcode 1424: Diagonal Traverse II"
date = "2024-06-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1424: Diagonal Traverse II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/diagonal-traverse-ii/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size(), n = nums[0].size(), mx = 0;
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < nums.size(); i++)
        for(int j = 0; j < nums[i].size(); j++) {
            mp[i + j].push_back(nums[i][j]);
            mx = max(mx, i + j);
        }

        vector<int> ans;
        for(int i = 0; i <= mx; i++) {
            for(auto x = mp[i].rbegin(); x != mp[i].rend(); x++)
            ans.push_back(*x);
        }
        return ans;
    }
};

/*
    Primary attempt can redirect to two pointer simulation
    But right attempt is, queueing over a map which shares same diagonals
*/
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1424.md" >}}
---
{{< youtube k4YsQgeJBt0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #1425: Constrained Subsequence Sum](https://grid47.xyz/posts/leetcode-1425-constrained-subsequence-sum-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

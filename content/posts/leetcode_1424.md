
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 1424: Diagonal Traverse II"
date = "2020-12-06"
description = "Solution to Leetcode 1424"
tags = [
    
]
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



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 2815: Max Pair Sum in an Array"
date = "2017-02-14"
description = "Solution to Leetcode 2815"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/max-pair-sum-in-an-array/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        vector<vector<int>> ids(10);
        
        for(int x: nums) {
            int val = x;
            int f = x % 10;
            while(x > 0) {
                f = max(f, x % 10);
                x /= 10;
            }
            ids[f].push_back(val);            
        }
        int ans = -1;
        for(int i = 0; i < ids.size(); i++) {
            sort(ids[i].begin(), ids[i].end());
            int n = ids[i].size();
            if(ids[i].size() >= 2) {
                // cout << ids[i][n - 1] << " " << ids[i][n - 2] << " "<< ids[i][n - 1] + ids[i][n - 2] << "\n";
                ans = max(ans, ids[i][n - 1] + ids[i][n - 2]);
            }
        }
        return ans;
    }
};
{{< /highlight >}}



{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}

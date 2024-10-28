
+++
authors = ["Yasir"]
title = "Leetcode 1906: Minimum Absolute Difference Queries"
date = "2019-08-11"
description = "Solution to Leetcode 1906"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/minimum-absolute-difference-queries/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& q) {

        int prefix[100001][101] = {}, cnt[101] = {};
        
        int n = nums.size(), m = q.size();
        
        for(int i = 0; i < n; i++) {
            cnt[nums[i]]++;
            for(int j = 1; j < 101; j++) prefix[i + 1][j] = cnt[j];
        }
        vector<int> ans;
        for(int i = 0; i < m; i++) {
            int l = q[i][0], r = q[i][1];
            int frq[101] = {};
            for(int j = 1; j < 101; j++) frq[j] = prefix[r + 1][j] - prefix[l][j];
            int prv = -1, mn = INT_MAX;
            for(int j = 1; j < 101; j++) {
                if(frq[j] == 0) continue;
                if(prv != -1 && j - prv < mn) mn = j - prv;
                prv = j;
            }
            ans.push_back(mn == INT_MAX? -1: mn);
        }
        
        return ans;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


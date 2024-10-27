
+++
authors = ["Yasir"]
title = "Leetcode 373: Find K Pairs with Smallest Sums"
date = "2023-10-21"
description = "Solution to Leetcode 373"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n1 = nums1.size(), n2 = nums2.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;        
        for(int i = 0; i < n1 && i < k; i++) {
            pq.push({nums1[i] + nums2[0], nums1[i], nums2[0], 0});
        }
        while(!pq.empty() && ans.size() < k) {
            auto it = pq.top();
            pq.pop();
            ans.push_back({it[1], it[2]});
            if(it[3] == n2 - 1) continue;            
            it[0] = it[1] + nums2[it[3] + 1];
            it[2] = nums2[it[3] + 1];
            it[3] = it[3] + 1;
            pq.push(it);
        }
        return ans;
    }
};
{{< /highlight >}}


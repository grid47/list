
+++
authors = ["Yasir"]
title = "Leetcode 347: Top K Frequent Elements"
date = "2023-11-15"
description = "Solution to Leetcode 347"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/top-k-frequent-elements/description/)

---

**Code:**

{{< highlight html >}}
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> ma;
        for(int x: nums)
            ma[x]++;
        
        priority_queue<pair<int, int>> pq;
        
        for(auto [key, val]: ma)
            pq.push(make_pair(val, key));
        
        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
{{< /highlight >}}


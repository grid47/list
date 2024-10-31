
+++
authors = ["Crafted by Me"]
title = "Leetcode 347: Top K Frequent Elements"
date = "2023-11-20"
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

{{< youtube jFZx4Q7UL5c >}}

**Code:**

{{< highlight cpp >}}
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/347.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


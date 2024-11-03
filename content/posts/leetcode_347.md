
+++
authors = ["Crafted by Me"]
title = "Leetcode 347: Top K Frequent Elements"
date = "2023-11-21"
description = "In-depth solution and explanation for Leetcode 347: Top K Frequent Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
---
{{< youtube jFZx4Q7UL5c >}}
| Next : [LeetCode #348: Design Tic-Tac-Toe](https://grid47.xyz/posts/leetcode_348) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


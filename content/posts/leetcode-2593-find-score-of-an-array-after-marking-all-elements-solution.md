
+++
authors = ["grid47"]
title = "Leetcode 2593: Find Score of an Array After Marking All Elements"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2593: Find Score of an Array After Marking All Elements in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Sorting","Heap (Priority Queue)","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++)
            pq.push({nums[i], i});
        
        while(!pq.empty()) {
            while(!pq.empty() && mp.count(pq.top()[1])) pq.pop();
            if(!pq.empty()) {
                score += pq.top()[0];
                mp[pq.top()[1]] = true;
                mp[pq.top()[1] + 1] = true;
                mp[pq.top()[1] - 1] = true;                
                pq.pop();
            }
        }
        return score;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2593.md" >}}
---
{{< youtube 6KKgxkXPtsQ >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2594: Minimum Time to Repair Cars](https://grid47.xyz/posts/leetcode-2594-minimum-time-to-repair-cars-solution/) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
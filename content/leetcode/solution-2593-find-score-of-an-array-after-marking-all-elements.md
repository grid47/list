
+++
authors = ["grid47"]
title = "Leetcode 2593: Find Score of an Array After Marking All Elements"
date = "2024-02-21"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2594: Minimum Time to Repair Cars](https://grid47.xyz/leetcode/solution-2594-minimum-time-to-repair-cars/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 1834: Single-Threaded CPU"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1834: Single-Threaded CPU in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/single-threaded-cpu/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        for(int i = 0; i < tasks.size(); i++)
            tasks[i].push_back(i);
        
        sort(tasks.begin(), tasks.end());
        
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        long i = 0, time = 0;
        while(i < tasks.size() || pq.size()) {

            if(pq.empty()) {
                time = max(time, (long) tasks[i][0]);
            }
            
            while(i < tasks.size() && tasks[i][0] <= time) {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            
            auto [pro, idx] = pq.top();
            pq.pop();
            time += pro;
            ans.push_back(idx);

        }

        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1834.md" >}}
---
{{< youtube RR1n-d4oYqE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1837: Sum of Digits in Base K](https://grid47.xyz/leetcode/solution-1837-sum-of-digits-in-base-k/) |
| --- |

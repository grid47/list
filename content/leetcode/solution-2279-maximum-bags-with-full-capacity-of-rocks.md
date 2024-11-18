
+++
authors = ["grid47"]
title = "Leetcode 2279: Maximum Bags With Full Capacity of Rocks"
date = "2024-03-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2279: Maximum Bags With Full Capacity of Rocks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rock, int cnt) {
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int n = rock.size();
        
        for(int i = 0; i < n; i++)
            pq.push(cap[i] - rock[i]);
        
        int res = 0;
        
        while(!pq.empty() && cnt >= pq.top()) {
            res++;
            cnt -= pq.top();
            pq.pop();
        }
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2279.md" >}}
---
{{< youtube 8s25uCT7vhY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2280: Minimum Lines to Represent a Line Chart](https://grid47.xyz/leetcode/solution-2280-minimum-lines-to-represent-a-line-chart/) |
| --- |

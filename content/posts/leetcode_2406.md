
+++
authors = ["Crafted by Me"]
title = "Leetcode 2406: Divide Intervals Into Minimum Number of Groups"
date = "2018-04-02"
description = "In-depth solution and explanation for Leetcode 2406: Divide Intervals Into Minimum Number of Groups in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minGroups(vector<vector<int>>& list) {
        sort(list.begin(), list.end());
        
        int res = 1, cnt = 1;
        priority_queue<int, vector<int>, greater<int>> pq;
                
        int n = list.size();
        
        pq.push(list[0][1]);
        
        if(n == 1) return 1;
        for(int i = 1; i < n; i++) {
            int next = list[i][0];            
            while(!pq.empty() && next > pq.top()) {
                pq.pop();
                cnt--;
            }
            pq.push(list[i][1]);
            cnt++;
            res = max(res, cnt);
        }
        return res;
    }
};
{{< /highlight >}}


---


| Next : [LeetCode #2407: Longest Increasing Subsequence II](grid47.xyz/leetcode_2407) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


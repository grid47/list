
+++
authors = ["Crafted by Me"]
title = "Leetcode 2279: Maximum Bags With Full Capacity of Rocks"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2279: Maximum Bags With Full Capacity of Rocks in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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


---
{{< youtube 8s25uCT7vhY >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2280: Minimum Lines to Represent a Line Chart](https://grid47.xyz/posts/leetcode_2280) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Crafted by Me"]
title = "Leetcode 1834: Single-Threaded CPU"
date = "2019-10-26"
description = "In-depth solution and explanation for Leetcode 1834: Single-Threaded CPU in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
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


---
{{< youtube RR1n-d4oYqE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1835: Find XOR Sum of All Pairs Bitwise AND](https://grid47.xyz/posts/leetcode_1835) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


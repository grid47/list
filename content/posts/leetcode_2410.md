
+++
authors = ["Crafted by Me"]
title = "Leetcode 2410: Maximum Matching of Players With Trainers"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 2410: Maximum Matching of Players With Trainers in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& man, vector<int>& master) {
        
        priority_queue<int, vector<int>, greater<int>> pq, qq;
        
        int m = man.size(), n = master.size();
        
        for(int i = 0; i < m; i++) {
            pq.push(man[i]);
        }
        for(int i = 0; i < n; i++) {
            qq.push(master[i]);
        }
        int cnt = 0;
        while(!pq.empty() && !qq.empty()) {
            while(!qq.empty() && pq.top() > qq.top())
                qq.pop();
            if(!qq.empty()) {
                cnt++;
                qq.pop();
                pq.pop();
            }
        }
        
        return cnt;
    }
};
{{< /highlight >}}


---
{{< youtube rvASCADV4Lw >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #2411: Smallest Subarrays With Maximum Bitwise OR](https://grid47.xyz/posts/leetcode_2411) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


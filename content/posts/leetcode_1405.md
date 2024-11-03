
+++
authors = ["Crafted by Me"]
title = "Leetcode 1405: Longest Happy String"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1405: Longest Happy String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/longest-happy-string/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int, char>>> pq;
        if(a > 0)
        pq.push({a, 'a'});
        if(b > 0)
        pq.push({b, 'b'});
        if(c > 0)
        pq.push({c, 'c'});
        
        string res = "";
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            res += string(min(2, it.first), it.second);
            it.first -= min(2, it.first);
            
            if(pq.empty()) break;
            auto it2 = pq.top();
            pq.pop();
            res += string(min(it.first > it2.first? 1: 2, it2.first), it2.second);
            it2.first -= min(it.first > it2.first? 1: 2, it2.first);
            
            if(it.first > 0) pq.push(it);
            if(it2.first > 0) pq.push(it2);
        }
        
        return res;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1405.md" >}}
---
{{< youtube 8u-H6O_XQKE >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1406: Stone Game III](https://grid47.xyz/posts/leetcode_1406) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


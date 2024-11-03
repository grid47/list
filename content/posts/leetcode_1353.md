
+++
authors = ["Crafted by Me"]
title = "Leetcode 1353: Maximum Number of Events That Can Be Attended"
date = "2021-02-18"
description = "In-depth solution and explanation for Leetcode 1353: Maximum Number of Events That Can Be Attended in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if(a[0] == b[0]) return a[1] < b[1];
        else return a[0] < b[0];
    }
    
    int maxEvents(vector<vector<int>>& e) {
        
        int n = e.size();
        sort(e.begin(), e.end(), cmp);
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0, cnt = 0;
        for(int d = 1; d <= 100000; d++) {
            while(!pq.empty() && pq.top() < d) {
                pq.pop();
            }
            while(i < n && e[i][0] == d) {
                pq.push(e[i++][1]);
            }
            if(!pq.empty()) {
                pq.pop();
                cnt++;
            }
        }

        return cnt;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1353.md" >}}
---


{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


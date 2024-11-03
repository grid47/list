
+++
authors = ["Crafted by Me"]
title = "Leetcode 973: K Closest Points to Origin"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 973: K Closest Points to Origin in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/k-closest-points-to-origin/description/)

---

**Code:**

{{< highlight cpp >}}
class cmp {
    public:
    bool operator()(vector<int> &a, vector<int> &b) {
        return a[0] * a[0] + a[1] * a[1] > b[0]* b[0] + b[1] * b[1];
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        for(auto it : pts) {
            pq.push(it);
        }
        
        vector<vector<int>> ans;
        while(k--) {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/973.md" >}}
---
{{< youtube IGRUukbD6p8 >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #974: Subarray Sums Divisible by K](https://grid47.xyz/posts/leetcode_974) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


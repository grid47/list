
+++
authors = ["grid47"]
title = "Leetcode 973: K Closest Points to Origin"
date = "2024-08-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 973: K Closest Points to Origin in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Divide and Conquer","Geometry","Sorting","Heap (Priority Queue)","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "IGRUukbD6p8"
img_src = ""
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #974: Subarray Sums Divisible by K](https://grid47.xyz/leetcode/solution-974-subarray-sums-divisible-by-k/) |
| --- |

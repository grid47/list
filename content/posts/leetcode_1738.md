
+++
authors = ["Crafted by Me"]
title = "Leetcode 1738: Find Kth Largest XOR Coordinate Value"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1738: Find Kth Largest XOR Coordinate Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/find-kth-largest-xor-coordinate-value/description/)

---

**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int kthLargestValue(vector<vector<int>>& mtx, int k) {
        int m = mtx.size(), n = mtx[0].size();
        for(int i = 0; i < m; i++) {
        for(int j = 1; j < n; j++) {
            mtx[i][j] = mtx[i][j-1]^mtx[i][j];}
        }
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < m; j++) {
                mtx[j][i] = mtx[j -1][i]^mtx[j][i]; }
        }
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0; i < m; i++) {
            for(int j= 0; j < n; j++) {
                if(pq.size() < k) {
                    pq.push(mtx[i][j]); }
        else {
            
            if(pq.top() < mtx[i][j]) {
                pq.pop();
                pq.push(mtx[i][j]);
            }
            
            }
                }
            }
        
        return pq.top();
    }
    

};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1738.md" >}}
---

| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1739: Building Boxes](https://grid47.xyz/posts/leetcode_1739) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


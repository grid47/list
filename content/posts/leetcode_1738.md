
+++
authors = ["Yasir"]
title = "Leetcode 1738: Find Kth Largest XOR Coordinate Value"
date = "2020-01-25"
description = "Solution to Leetcode 1738"
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

{{< highlight html >}}
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


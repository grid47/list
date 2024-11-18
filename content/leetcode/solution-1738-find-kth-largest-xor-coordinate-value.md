
+++
authors = ["grid47"]
title = "Leetcode 1738: Find Kth Largest XOR Coordinate Value"
date = "2024-05-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1738: Find Kth Largest XOR Coordinate Value in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Bit Manipulation","Sorting","Heap (Priority Queue)","Matrix","Prefix Sum","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "3geaHSLu4PA"
youtube_upload_date="2021-01-24"
youtube_thumbnail="https://i.ytimg.com/vi/3geaHSLu4PA/maxresdefault.jpg"
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
{{< youtube 3geaHSLu4PA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1742: Maximum Number of Balls in a Box](https://grid47.xyz/leetcode/solution-1742-maximum-number-of-balls-in-a-box/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 378: Kth Smallest Element in a Sorted Matrix"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 378: Kth Smallest Element in a Sorted Matrix in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting","Heap (Priority Queue)","Matrix"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/378.webp"
youtube = "PKj4LyF5iCk"
youtube_upload_date="2021-01-24"
youtube_thumbnail="https://i.ytimg.com/vi/PKj4LyF5iCk/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/378.webp" 
    alt="A matrix where the kth smallest element glows softly, showing its position within the sorted matrix."
    caption="Solution to LeetCode 378: Kth Smallest Element in a Sorted Matrix Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mtx, int k) {
        int m = mtx.size(), n = mtx[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        for(int r = 0; r < min(m, k); r++)
            pq.push({mtx[r][0], r, 0});
        
        vector<int> cur;
        while(k-- > 1 && !pq.empty()) {
            
            cur = pq.top();
            pq.pop();
            
            if(cur[2] + 1 < n)
            pq.push({ mtx[cur[1]][cur[2] + 1], cur[1], cur[2] + 1 });
            
        }
        
        cur = pq.top();
        
        return cur[0];
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/378.md" >}}
---
{{< youtube PKj4LyF5iCk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #380: Insert Delete GetRandom O(1)](https://grid47.xyz/leetcode/solution-380-insert-delete-getrandom-o1/) |
| --- |
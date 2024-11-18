
+++
authors = ["grid47"]
title = "Leetcode 215: Kth Largest Element in an Array"
date = "2024-10-16"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 215: Kth Largest Element in an Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Divide and Conquer","Sorting","Heap (Priority Queue)","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/kth-largest-element-in-an-array/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/215.webp" 
    alt="An array of glowing elements with the kth largest element glowing brighter than the others."
    caption="Solution to LeetCode 215: Kth Largest Element in an Array Problem"
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
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int x: nums)
            pq.push(x);
        
        int x;
        while(k-->0) {
            x = pq.top();
            pq.pop();
        }
        return x;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/215.md" >}}
---
{{< youtube ZmGk7h8KZLs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #217: Contains Duplicate](https://grid47.xyz/leetcode/solution-217-contains-duplicate/) |
| --- |

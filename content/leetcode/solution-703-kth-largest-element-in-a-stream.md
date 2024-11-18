
+++
authors = ["grid47"]
title = "Leetcode 703: Kth Largest Element in a Stream"
date = "2024-08-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 703: Kth Largest Element in a Stream in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Tree","Design","Binary Search Tree","Heap (Priority Queue)","Binary Tree","Data Stream"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "hOjcdrqMoQ8"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/703.webp"
+++



[`Problem Link`](https://leetcode.com/problems/kth-largest-element-in-a-stream/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/703.webp" 
    alt="A stream of numbers where the kth largest element is identified, glowing brightly as it’s found."
    caption="Solution to LeetCode 703: Kth Largest Element in a Stream Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto x: nums) {
            pq.push(x);
            if(pq.size() > k) {
                cout << pq.top();
                pq.pop();
            }

        }

    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/703.md" >}}
---
{{< youtube hOjcdrqMoQ8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #704: Binary Search](https://grid47.xyz/leetcode/solution-704-binary-search/) |
| --- |

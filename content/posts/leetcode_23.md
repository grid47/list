
+++
authors = ["grid47"]
title = "Leetcode 23: Merge k Sorted Lists"
date = "2024-11-01"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 23: Merge k Sorted Lists in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Divide and Conquer","Heap (Priority Queue)","Merge Sort"]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-k-sorted-lists/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/23.jpeg" 
    alt="Multiple paths of light merging into one bright, unified stream."
    caption="Solution to LeetCode 23: Merge k Sorted Lists Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class cmp {
    public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        
        for(auto it: lists) {
            if(it != NULL) 
                pq.push(it);            
        }
        
        ListNode* h = new ListNode(0);
        ListNode* tmp = h;
        
        while(!pq.empty()) {
            auto it = pq.top();
            tmp->next = it;
            tmp = tmp->next;
            pq.pop();
            if(it->next)
                pq.push(it->next);
        }
        tmp->next = NULL;
        return h->next;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/23.md" >}}
---
{{< youtube q5a5OiGbT6Q >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #24: Swap Nodes in Pairs](https://grid47.xyz/posts/leetcode_24) |
| --- |
{{< notice info >}}
| [DP-List](https://grid47.xyz/lists/dp/) | [Graph-List](https://grid47.xyz/lists/graph/) | [Heap-List](https://grid47.xyz/lists/heap/) | [Interval-List](https://grid47.xyz/lists/interval/) | [Linked-List](https://grid47.xyz/lists/ll/) | [Tree](https://grid47.xyz/lists/tree/) |
{{< /notice >}}
| |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}

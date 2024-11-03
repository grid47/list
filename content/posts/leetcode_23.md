
+++
authors = ["Crafted by Me"]
title = "Leetcode 23: Merge k Sorted Lists"
date = "2024-10-10"
description = "In-depth solution and explanation for Leetcode 23: Merge k Sorted Lists in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Hard"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/merge-k-sorted-lists/description/)

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
| Next : [LeetCode #24: Swap Nodes in Pairs](https://grid47.xyz/posts/leetcode_24) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


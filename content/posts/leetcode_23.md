
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 23: Merge k Sorted Lists"
date = "2024-10-07"
description = "Solution to Leetcode 23"
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

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


+++
authors = ["Yasir"]
title = "Leetcode 23: Merge k Sorted Lists"
date = "2024-10-04"
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

{{< highlight html >}}
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


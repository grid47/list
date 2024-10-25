
+++
authors = ["Yasir"]
title = "Leetcode 445: Add Two Numbers II"
date = "2023-08-09"
description = "Solution to Leetcode 445"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/add-two-numbers-ii/description/)

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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        
        while(l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        
        int cry = 0;
        
        ListNode* node = NULL, *prv = NULL;
        
        while(!s1.empty() || !s2.empty()) {
            
            if(!s1.empty()) {
                cry += s1.top();
                s1.pop();
            }

            if(!s2.empty()) {
                cry += s2.top();
                s2.pop();
            }
            
            node = new ListNode(cry % 10);
            node->next = prv;
            
            prv = node;
            cry /= 10;
            
        }
        
        if(cry != 0) {
            node = new ListNode(cry %10);
            node->next = prv;
            
        }
        
        return node;
    }
};
{{< /highlight >}}


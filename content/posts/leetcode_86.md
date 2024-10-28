
+++
authors = ["Yasir"]
title = "Leetcode 86: Partition List"
date = "2024-08-04"
description = "Solution to Leetcode 86"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-list/description/)

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
    ListNode* partition(ListNode* head, int x) {
        
        ListNode* p1 = new ListNode(0);
        ListNode* p2 = new ListNode(0);        
        
        ListNode* ans = p1, *r = p2;
        
        while(head) {
            if(head->val < x) {
                p1->next = new ListNode(head->val);
                p1 = p1->next;
            } else {
                p2->next = new ListNode(head->val);
                p2 = p2->next;                
            }
            head = head->next;
        }

        p1->next = r->next;
        return ans->next;
    }
};
{{< /highlight >}}


{{< notice tip >}}
[Check out my Momentum Learning course on Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


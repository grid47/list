
+++
authors = ["Coded by Me, Explained by GPT"]
title = "Leetcode 19: Remove Nth Node From End of List"
date = "2024-10-12"
description = "Solution to Leetcode 19"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

---
{{< youtube XVuQxVej6y8 >}}
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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        int sz = 0;
        while(node) {
            node = node->next;
            sz++;
        }
        node = head;
        int tgt = sz - n;
        if(sz == n) return head->next;
        for(int i = 0; i < tgt-1; i++)
            node = node->next;
        if(node->next)
        node->next = node->next->next;
        
        return head;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/19.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


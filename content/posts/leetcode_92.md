
+++
authors = ["Coded by Yasir, Explained by GPT"]
title = "Leetcode 92: Reverse Linked List II"
date = "2024-07-29"
description = "Solution to Leetcode 92"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-linked-list-ii/description/)

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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next     = head;
        ListNode* pre   = dummy;
        for(int i = 1; i < left; i++)
            pre = pre->next;

        ListNode* start =   pre->next;
        ListNode* then  = start->next;

        for(int i = 0; i < right - left; i++) {
            start->next =  then->next;
             then->next =   pre->next;
              pre->next = then;
            then        = start->next;
        }
        return dummy->next;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/92.md" >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}



+++
authors = ["Yasir"]
title = "Leetcode 206: Reverse Linked List"
date = "2024-04-05"
description = "Solution to Leetcode 206"
tags = [
    
]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-linked-list/description/)

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
    ListNode* reverseList(ListNode* head) {
        ListNode* nxt, *prv = NULL;
        while(head) {
            nxt = head->next;
            head->next = prv;
            prv = head;
            head = nxt;
        }
        return prv;
    }
};
{{< /highlight >}}


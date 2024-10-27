
+++
authors = ["Yasir"]
title = "Leetcode 2487: Remove Nodes From Linked List"
date = "2018-01-06"
description = "Solution to Leetcode 2487"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-nodes-from-linked-list/description/)

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
    ListNode* removeNodes(ListNode* head) {
        if(head == NULL) return NULL;
        head->next = removeNodes(head->next);
        return head->next != NULL && head->val < head->next->val ? head->next: head;
    }
};
{{< /highlight >}}


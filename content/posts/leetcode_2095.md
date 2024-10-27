
+++
authors = ["Yasir"]
title = "Leetcode 2095: Delete the Middle Node of a Linked List"
date = "2019-02-02"
description = "Solution to Leetcode 2095"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/)

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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode* slw = head, *fst = head->next->next;
        while(fst && fst->next) {
            fst = fst->next->next;
            slw = slw->next;
        }
        slw->next = slw->next->next;
        return head;
    }
};
{{< /highlight >}}


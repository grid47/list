
+++
authors = ["Crafted by Me"]
title = "Leetcode 2095: Delete the Middle Node of a Linked List"
date = "2019-02-07"
description = "In-depth solution and explanation for Leetcode 2095: Delete the Middle Node of a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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


---


| Next : [LeetCode #2096: Step-By-Step Directions From a Binary Tree Node to Another](grid47.xyz/leetcode_2096) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


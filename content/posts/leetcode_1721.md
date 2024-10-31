
+++
authors = ["Crafted by Me"]
title = "Leetcode 1721: Swapping Nodes in a Linked List"
date = "2020-02-15"
description = "Solution to Leetcode 1721"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/swapping-nodes-in-a-linked-list/description/)

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* n1 = nullptr, *n2 = nullptr;
        for(ListNode *p = head; p != nullptr; p = p->next) {
            n2 = n2 == nullptr? nullptr: n2->next;
            if(--k == 0) {
                n1 = p;
                n2 = head;
            }
        }
        swap(n2->val, n1->val);
        return head;
    }
};
{{< /highlight >}}



---

{{< youtube KUTRaNOzmoo >}}

{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


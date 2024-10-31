
+++
authors = ["Crafted by Me"]
title = "Leetcode 2816: Double a Number Represented as a Linked List"
date = "2017-02-15"
description = "Solution to Leetcode 2816"
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/)

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
    int pin(ListNode* head) {
        if(head == NULL) return 0;
        int val = pin(head->next);
        int num = head->val;
        num = num * 2 + val;
        head->val = num % 10;
        return num/10;
    }

    ListNode* doubleIt(ListNode* head) {
        int num = pin(head);
        while(num > 0) {
            int c = num % 10;
            num /= 10;
            ListNode* node = new ListNode(c);
            node->next = head;
            head = node;
        }
        return head;
    }
};
{{< /highlight >}}


---


{{< notice tip >}}
[Check out my Momentum Learning course at Udemy! 🚀 "](https://www.udemy.com/course/blind-75-the-data-structures-and-algorithms-essentials/)
{{< /notice >}}


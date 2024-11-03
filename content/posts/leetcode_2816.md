
+++
authors = ["Crafted by Me"]
title = "Leetcode 2816: Double a Number Represented as a Linked List"
date = "2017-02-16"
description = "In-depth solution and explanation for Leetcode 2816: Double a Number Represented as a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
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
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


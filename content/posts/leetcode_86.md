
+++
authors = ["Crafted by Me"]
title = "Leetcode 86: Partition List"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 86: Partition List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = ["Linked List","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/partition-list/description/)

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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/86.md" >}}
---
{{< youtube KT1iUciJr4g >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #87: Scramble String](https://grid47.xyz/posts/leetcode_87) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


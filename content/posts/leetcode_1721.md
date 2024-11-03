
+++
authors = ["Crafted by Me"]
title = "Leetcode 1721: Swapping Nodes in a Linked List"
date = "2024-11-01"
description = "In-depth solution and explanation for Leetcode 1721: Swapping Nodes in a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = []
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

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1721.md" >}}
---
{{< youtube KUTRaNOzmoo >}}
| [LeetCode Exercise Compilation](https://grid47.xyz/leetcode/) / Next : [LeetCode #1722: Minimize Hamming Distance After Swap Operations](https://grid47.xyz/posts/leetcode_1722) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


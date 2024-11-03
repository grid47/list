
+++
authors = ["Crafted by Me"]
title = "Leetcode 143: Reorder List"
date = "2024-06-12"
description = "In-depth solution and explanation for Leetcode 143: Reorder List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reorder-list/description/)

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
    void reorderList(ListNode* head) {
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* next, *prev = NULL;
        while(mid) {
            next = mid->next;
            mid->next = prev;
            prev = mid;
            mid = next;
        }
        ListNode* l1 = head, *l2 = prev;
        while(l1 && l2) {
            ListNode* tmp1 = l1->next;
            l1->next = l2;
            ListNode* tmp2 = l2->next;
            l2->next = tmp1;
            l1 = tmp1;
            l2 = tmp2;
        }
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/143.md" >}}
---
{{< youtube i3HU4Ur3-uM >}}
| Next : [LeetCode #144: Binary Tree Preorder Traversal](https://grid47.xyz/posts/leetcode_144) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}



+++
authors = ["Crafted by Me"]
title = "Leetcode 19: Remove Nth Node From End of List"
date = "2024-10-14"
description = "In-depth solution and explanation for Leetcode 19: Remove Nth Node From End of List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis—more insightful than official and community solutions."
tags = [
    
]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = head;
        int sz = 0;
        while(node) {
            node = node->next;
            sz++;
        }
        node = head;
        int tgt = sz - n;
        if(sz == n) return head->next;
        for(int i = 0; i < tgt-1; i++)
            node = node->next;
        if(node->next)
        node->next = node->next->next;
        
        return head;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/19.md" >}}
---
{{< youtube XVuQxVej6y8 >}}
| Next : [LeetCode #20: Valid Parentheses](https://grid47.xyz/posts/leetcode_20) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}


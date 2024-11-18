
+++
authors = ["grid47"]
title = "Leetcode 1721: Swapping Nodes in a Linked List"
date = "2024-05-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1721: Swapping Nodes in a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers"]
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1722: Minimize Hamming Distance After Swap Operations](https://grid47.xyz/leetcode/solution-1722-minimize-hamming-distance-after-swap-operations/) |
| --- |

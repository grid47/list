
+++
authors = ["grid47"]
title = "Leetcode 143: Reorder List"
date = "2024-10-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 143: Reorder List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers","Stack","Recursion"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "i3HU4Ur3-uM"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/143.webp"
+++



[`Problem Link`](https://leetcode.com/problems/reorder-list/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/143.webp" 
    alt="A series of list items gently swapping positions, forming a balanced sequence."
    caption="Solution to LeetCode 143: Reorder List Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #144: Binary Tree Preorder Traversal](https://grid47.xyz/leetcode/solution-144-binary-tree-preorder-traversal/) |
| --- |

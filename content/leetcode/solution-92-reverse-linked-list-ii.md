
+++
authors = ["grid47"]
title = "Leetcode 92: Reverse Linked List II"
date = "2024-10-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 92: Reverse Linked List II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/reverse-linked-list-ii/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/92.webp" 
    alt="A linked list gently reversing, glowing softly with each node that changes position."
    caption="Solution to LeetCode 92: Reverse Linked List II Problem"
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next     = head;
        ListNode* pre   = dummy;
        for(int i = 1; i < left; i++)
            pre = pre->next;

        ListNode* start =   pre->next;
        ListNode* then  = start->next;

        for(int i = 0; i < right - left; i++) {
            start->next =  then->next;
             then->next =   pre->next;
              pre->next = then;
            then        = start->next;
        }
        return dummy->next;        
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/92.md" >}}
---
{{< youtube RF_M9tX4Eag >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #94: Binary Tree Inorder Traversal](https://grid47.xyz/leetcode/solution-94-binary-tree-inorder-traversal/) |
| --- |

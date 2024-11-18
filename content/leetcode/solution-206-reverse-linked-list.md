
+++
authors = ["grid47"]
title = "Leetcode 206: Reverse Linked List"
date = "2024-10-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 206: Reverse Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Recursion"]
categories = [
    "Easy"
]
series = ["Leetcode"]
youtube = "W-EfGB0E_ao"
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/206.webp"
+++



[`Problem Link`](https://leetcode.com/problems/reverse-linked-list/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/206.webp" 
    alt="A linked list where nodes glow and reverse in position, flowing smoothly backward."
    caption="Solution to LeetCode 206: Reverse Linked List Problem"
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
    ListNode* reverseList(ListNode* head) {
        ListNode* nxt, *prv = NULL;
        while(head) {
            nxt = head->next;
            head->next = prv;
            prv = head;
            head = nxt;
        }
        return prv;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/206.md" >}}
---
{{< youtube W-EfGB0E_ao >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #207: Course Schedule](https://grid47.xyz/leetcode/solution-207-course-schedule/) |
| --- |

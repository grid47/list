
+++
authors = ["grid47"]
title = "Leetcode 1669: Merge In Between Linked Lists"
date = "2024-05-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1669: Merge In Between Linked Lists in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List"]
categories = [
    "Medium"
]
series = ["Leetcode"]
youtube = "pI775VutBxg"
img_src = ""
+++



[`Problem Link`](https://leetcode.com/problems/merge-in-between-linked-lists/description/)

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* f = list1, *s = list1;
        for(int i = 0; i < a-1; i++) f = f->next;
        for(int i = 0; i < b; i++) s = s->next;
        f->next = list2;
        while(list2->next) list2 = list2->next;
        list2->next = s->next;
        return list1;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/1669.md" >}}
---
{{< youtube pI775VutBxg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #1670: Design Front Middle Back Queue](https://grid47.xyz/leetcode/solution-1670-design-front-middle-back-queue/) |
| --- |

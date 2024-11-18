
+++
authors = ["grid47"]
title = "Leetcode 2095: Delete the Middle Node of a Linked List"
date = "2024-04-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2095: Delete the Middle Node of a Linked List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "gwel0eQ0MhA"
youtube_upload_date="2021-12-05"
youtube_thumbnail="https://i.ytimg.com/vi_webp/gwel0eQ0MhA/maxresdefault.webp"
+++



[`Problem Link`](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/description/)

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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode* slw = head, *fst = head->next->next;
        while(fst && fst->next) {
            fst = fst->next->next;
            slw = slw->next;
        }
        slw->next = slw->next->next;
        return head;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2095.md" >}}
---
{{< youtube gwel0eQ0MhA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #2096: Step-By-Step Directions From a Binary Tree Node to Another](https://grid47.xyz/leetcode/solution-2096-step-by-step-directions-from-a-binary-tree-node-to-another/) |
| --- |


+++
authors = ["grid47"]
title = "Leetcode 21: Merge Two Sorted Lists"
date = "2024-11-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 21: Merge Two Sorted Lists in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Recursion"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/21.webp"
youtube = "XIdigk956u0"
youtube_upload_date="2020-08-19"
youtube_thumbnail="https://i.ytimg.com/vi/XIdigk956u0/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/merge-two-sorted-lists/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/21.webp" 
    alt="Two glowing lists merging, with soft energy flowing together in sync."
    caption="Solution to LeetCode 21: Merge Two Sorted Lists Problem"
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        
        if(l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;            
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/21.md" >}}
---
{{< youtube XIdigk956u0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #22: Generate Parentheses](https://grid47.xyz/leetcode/solution-22-generate-parentheses/) |
| --- |
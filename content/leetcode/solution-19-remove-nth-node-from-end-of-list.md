
+++
authors = ["grid47"]
title = "Leetcode 19: Remove Nth Node From End of List"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 19: Remove Nth Node From End of List in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Linked List","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/19.webp"
youtube = "XVuQxVej6y8"
youtube_upload_date="2020-12-29"
youtube_thumbnail="https://i.ytimg.com/vi/XVuQxVej6y8/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/19.webp" 
    alt="A single node being gently removed from a glowing chain, leaving a calm, uninterrupted flow."
    caption="Solution to LeetCode 19: Remove Nth Node From End of List Problem"
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
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #20: Valid Parentheses](https://grid47.xyz/leetcode/solution-20-valid-parentheses/) |
| --- |
